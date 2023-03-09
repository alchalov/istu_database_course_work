#include "classes_window.h"
#include "ui_classes_window.h"

ClassesWindow::ClassesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClassesWindow)
{
    ui->setupUi(this);

    studentsWindow = new StudentsWindow();
    dialogEditClass = new DialogEditClass();
    schoolReport = new FormSchoolReport();
}

ClassesWindow::~ClassesWindow()
{
    delete ui;
}

void ClassesWindow::setSchool(int selectedSchool)
{
    currentSchool = selectedSchool;
}

void ClassesWindow::setDatabase(const QString &dbName)
{
    db.setDatabaseName(dbName);
}

void ClassesWindow::setupWindow()
{

    // Привязываемя базу данных к модели табличного представления
    modelClasses = new QSqlRelationalTableModel(this, db);
    modelClasses->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    modelClasses->clear();
    modelClasses->setTable("classes");
    modelClasses->setFilter(QStringLiteral("IdSchool = %1").arg(currentSchool));
    modelClasses->select();

    // Устанавливаем названия столбцов
    modelClasses->setHeaderData(2,Qt::Horizontal,
                                "Название класса");
    modelClasses->setHeaderData(3,Qt::Horizontal,
                                "ФИО классного\n"
                                "руководителя");
    modelClasses->setHeaderData(4,Qt::Horizontal,
                                "Телефон\n"
                                "классного\n"
                                "руководителя");

    // Настраиваем табличное представление таблицы базы данных
    ui->tableView->setModel(modelClasses);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Скрываем ненужные колонки и вертикальный заголовок
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);

    // Активируем элементы интерфейса
    ui->addClassButton->setEnabled(true);
    ui->editClassButton->setEnabled(true);
    ui->deleteClassButton->setEnabled(true);
    ui->goToStudentsButton->setEnabled(true);
    ui->loadClassesButton->setEnabled(true);
    ui->saveClassesButton->setEnabled(true);

    // Объявляем диалог изменения записей таблицы и привязываем его к таблице
    dialogEditClass = new DialogEditClass();
    dialogEditClass->setParent(this, Qt::Window);
    dialogEditClass->setModel(modelClasses);

    studentsWindow = new StudentsWindow();
    studentsWindow->setParent(this, Qt::Window);

}

void ClassesWindow::on_addClassButton_clicked()
{
    int lastRow = modelClasses->rowCount();
    modelClasses->insertRow(lastRow);
    modelClasses->setData(modelClasses->index(lastRow, 1), currentSchool);
    modelClasses->setData(modelClasses->index(lastRow, 2), "Неизвестно");
    modelClasses->setData(modelClasses->index(lastRow, 3), "Неизвестно");
    modelClasses->setData(modelClasses->index(lastRow, 4), "Неизвестно");
}

void ClassesWindow::on_editClassButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    QModelIndex index = modelClasses->index(selectedRow, 0);
    dialogEditClass->mapper->setCurrentModelIndex(index);
    dialogEditClass->show();
}



void ClassesWindow::on_deleteClassButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();

    if (selectedRow >= 0)
    {
        modelClasses->removeRow(selectedRow);
    }
}


void ClassesWindow::on_loadClassesButton_clicked()
{
    modelClasses->select();
}


void ClassesWindow::on_saveClassesButton_clicked()
{
    modelClasses->submitAll();
}


void ClassesWindow::on_goToStudentsButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    int idClass = modelClasses->record(selectedRow).value("IdClass").toInt();
    studentsWindow->setDatabase(db.databaseName());
    studentsWindow->setClass(idClass);

    studentsWindow->setupWindow();

    QString className = modelClasses->record(selectedRow).value("ClassName").toString();
    studentsWindow->setWindowTitle(QStringLiteral("Ученики класса %1 Школы %2").arg(className).arg(currentSchool));
    studentsWindow->show();
}


void ClassesWindow::on_actionSchoolReport_triggered()
{
    schoolReport->setCurrentSchool(currentSchool);
    schoolReport->doQuery();
    schoolReport->show();
}


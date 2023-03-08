#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    dialogAbout->show();
}

void MainWindow::on_actionConnectDB_triggered()
{
    // Устанавливаем соединение с базой данных
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={MySQL ODBC 8.0 Unicode Driver};DATABASE=city_schools;");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("user1");
    db.setPassword("123");

    if (!db.open())
    {
        qDebug() << db.lastError().text();
        return;
    }
    else
    {
        qDebug() << "Успешное подключение к базе данных";
    }

    // Привязываемя базу данных к модели табличного представления
    modelSchools = new QSqlRelationalTableModel(this, db);
    modelSchools->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    modelSchools->clear();
    modelSchools->setTable("schools");
    modelSchools->select();
    modelSchools->setHeaderData(1,Qt::Horizontal,
                                "Название\n"
                                "школы");
    modelSchools->setHeaderData(2,Qt::Horizontal,
                                "Тип школы");
    modelSchools->setHeaderData(3,Qt::Horizontal,
                                "Улица");
    modelSchools->setHeaderData(4,Qt::Horizontal,
                                "Номер дома");


    // Отображаем табличное представление таблицы базы данных
    ui->tableView->setModel(modelSchools);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->hideColumn(0);


    // Объявляем диалог изменения записей таблицы и привязываем его к таблице
    dialogEditSchool = new DialogEditSchool();
    dialogEditSchool->setParent(this, Qt::Window);
    dialogEditSchool->setModel(modelSchools);

    classesWindow = new ClassesWindow();
    classesWindow->setParent(this, Qt::Window);

    formFullReport = new FormFullReport();

    // Активируем элементы интерфейса
    ui->actionFullReport->setEnabled(true);
    ui->addSchoolButton->setEnabled(true);
    ui->editSchoolButton->setEnabled(true);
    ui->deleteSchoolButton->setEnabled(true);
    ui->goToClassesButton->setEnabled(true);
    ui->loadButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

void MainWindow::on_saveButton_clicked()
{
    modelSchools->submitAll();
}

void MainWindow::on_actionFullReport_triggered()
{
    formFullReport->setDatabase(db.databaseName());
    formFullReport->show();
}


void MainWindow::on_loadButton_clicked()
{
    modelSchools->select();
}

void MainWindow::on_addSchoolButton_clicked()
{
    int lastRow = modelSchools->rowCount();
    modelSchools->insertRow(lastRow);
    modelSchools->setData(modelSchools->index(lastRow, 1), 0);
    modelSchools->setData(modelSchools->index(lastRow, 2), "Неизвестно");
    modelSchools->setData(modelSchools->index(lastRow, 3), "Неизвестно");
    modelSchools->setData(modelSchools->index(lastRow, 4), "Неизвестно");
}


void MainWindow::on_deleteSchoolButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();

    if (selectedRow >= 0)
    {
        modelSchools->removeRow(selectedRow);
    }
}


void MainWindow::on_editSchoolButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();

    QModelIndex index = modelSchools->index(selectedRow, 0);
    dialogEditSchool->mapper->setCurrentModelIndex(index);
    dialogEditSchool->show();
}


void MainWindow::on_goToClassesButton_clicked()
{
    // Передаём в окно классов школы необходимые данные о выбранной школе
    int selectedRow = ui->tableView->currentIndex().row();
    int idSchool = modelSchools->record(selectedRow).value("IdSchool").toInt();
    classesWindow->setDatabase(db.databaseName());
    classesWindow->setSchool(idSchool);

    // Подготавливаем окно
    classesWindow->setupWindow();

    // Устанавливаем заголовок окна
    QString schoolName = modelSchools->record(selectedRow).value("SchoolName").toString();
    classesWindow->setWindowTitle(QStringLiteral("Классы школы %1").arg(schoolName));
    classesWindow->show();
}


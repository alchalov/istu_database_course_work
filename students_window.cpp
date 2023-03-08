#include "students_window.h"
#include "ui_students_window.h"

#include <QDebug>
#include <QSqlRecord>

StudentsWindow::StudentsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentsWindow)
{
    ui->setupUi(this);

}

StudentsWindow::~StudentsWindow()
{
    delete ui;
}

void StudentsWindow::setClass(int selectedClass)
{
    currentClass = selectedClass;
    qDebug() << currentClass;
}

void StudentsWindow::setDatabase(const QString &dbName)
{
    db.setDatabaseName(dbName);
}

void StudentsWindow::setupWindow()
{

    // Привязываемя базу данных к модели табличного представления
    modelStudents = new QSqlRelationalTableModel(this, db);
    modelStudents->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    modelStudents->clear();
    modelStudents->setTable("students");
    modelStudents->setFilter(QStringLiteral("IdClass = %1").arg(currentClass));
    modelStudents->select();

    // Устанавливаем названия столбцов
    modelStudents->setHeaderData(2,Qt::Horizontal,
                                 "Фамилия");
    modelStudents->setHeaderData(3,Qt::Horizontal,
                                 "Год рождения");
    modelStudents->setHeaderData(4,Qt::Horizontal,
                                 "Год поступления");
    modelStudents->setHeaderData(5,Qt::Horizontal,
                                 "Пол");

    // Отображаем табличное представление таблицы базы данных
    ui->tableView->setModel(modelStudents);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);

    // Активируем элементы интерфейса
    ui->addClassButton->setEnabled(true);
    ui->editClassButton->setEnabled(true);
    ui->deleteClassButton->setEnabled(true);
    ui->loadClassesButton->setEnabled(true);
    ui->saveClassesButton->setEnabled(true);

    // Объявляем диалог изменения записей таблицы и привязываем его к таблице
    dialogEditStudent = new DialogEditStudent();
    dialogEditStudent->setParent(this, Qt::Window);
    dialogEditStudent->setModel(modelStudents);

}

void StudentsWindow::on_addClassButton_clicked()
{
    int lastRow = modelStudents->rowCount();
    modelStudents->insertRow(lastRow);
    modelStudents->setData(modelStudents->index(lastRow, 1), currentClass);
    modelStudents->setData(modelStudents->index(lastRow, 2), "Неизвестно");
    modelStudents->setData(modelStudents->index(lastRow, 3), "2015");
    modelStudents->setData(modelStudents->index(lastRow, 4), "2023");
    modelStudents->setData(modelStudents->index(lastRow, 5), "Мальчик");

}


void StudentsWindow::on_editClassButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    QModelIndex index = modelStudents->index(selectedRow, 0);
    dialogEditStudent->mapper->setCurrentModelIndex(index);
    dialogEditStudent->show();

}


void StudentsWindow::on_deleteClassButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();

    if (selectedRow >= 0)
    {
        modelStudents->removeRow(selectedRow);
    }
}


void StudentsWindow::on_loadClassesButton_clicked()
{
    modelStudents->select();
}


void StudentsWindow::on_saveClassesButton_clicked()
{
    modelStudents->submitAll();
}


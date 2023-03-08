#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogabout.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout about;
    about.exec();
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
    model = new QSqlRelationalTableModel(this, db);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setTable("schools");
    model->select();

    // Отображаем табличное представление таблицы базы данных
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Объявляем диалог изменения записей таблицы и привязываем его к таблице
    dialogEditSchool = new DialogEditSchool();
    dialogEditSchool->setParent(this, Qt::Window);
    dialogEditSchool->setModel(model);

    // Активируем элементы интерфейса
    ui->actionFullReport->setEnabled(true);
    ui->addSchoolButton->setEnabled(true);
    ui->editSchoolButton->setEnabled(true);
    ui->deleteSchoolButton->setEnabled(true);
    ui->goToClassesButton->setEnabled(true);
    ui->loadButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->revertButton->setEnabled(true);
}

void MainWindow::on_revertButton_clicked()
{
    model->revertAll();
}


void MainWindow::on_saveButton_clicked()
{
    model->submitAll();
}


void MainWindow::on_loadButton_clicked()
{
    model->select();
}

void MainWindow::on_addSchoolButton_clicked()
{
    int lastRow = model->rowCount();
    model->insertRow(lastRow);
}


void MainWindow::on_deleteSchoolButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();

    if (selectedRow >= 0)
    {
        model->removeRow(selectedRow);
    }
}


void MainWindow::on_editSchoolButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    QModelIndex index = model->index(selectedRow, 0);
    dialogEditSchool->mapper->setCurrentModelIndex(index);
    dialogEditSchool->show();
}



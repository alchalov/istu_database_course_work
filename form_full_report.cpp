#include "form_full_report.h"
#include "ui_form_full_report.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

FormFullReport::FormFullReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFullReport)
{
    ui->setupUi(this);
}

FormFullReport::~FormFullReport()
{
    delete ui;
}

void FormFullReport::setDatabase(const QString& name)
{
    db.setDatabaseName(name);
}

void FormFullReport::doQuery()
{
    fullReportModel = new QSqlQueryModel();
    fullReportModel->setQuery("SELECT FamilyName, BornYear, JoinYear, Sex, SchoolName, ClassName, ClassTeacher, TeachersPhone, SchoolType, Street, HouseNum FROM students LEFT JOIN classes ON students.IdClass = classes.IdClass LEFT JOIN schools ON classes.IdSchool = schools.IdSchool");

    QList<QString> headers = {"Ученик", "Год\nрождения", "Год\nпоступления", "Пол","Класс", "Классный\n руководитель", "Номер\nтелефона", "Школа", "Тип", "Улица", "Дом"};
    QString header = "";
    int i = 0;

    foreach (header, headers)
    {
        fullReportModel->setHeaderData(i,Qt::Horizontal,header);
        ++i;
    }

    ui->tableView->setModel(fullReportModel);
    ui->tableView->show();
}


void FormFullReport::on_pushButton_clicked()
{
    close();
}


#include "form_full_report.h"
#include "ui_form_full_report.h"

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

void FormFullReport::doQuery()
{
    reportModel = new QSqlQueryModel();
    reportModel->setQuery("SELECT FamilyName, BornYear, JoinYear, Sex, ClassName, ClassTeacher, TeachersPhone, SchoolName, SchoolType, Street, HouseNum FROM students LEFT JOIN classes ON students.IdClass = classes.IdClass LEFT JOIN schools ON classes.IdSchool = schools.IdSchool");

    QList<QString> headers = {"Ученик", "Год\nрождения", "Год\nпоступления", "Пол","Класс", "Классный\n руководитель", "Номер\nтелефона", "Школа", "Тип", "Улица", "Дом"};
    QString header = "";
    int i = 0;

    foreach (header, headers)
    {
        reportModel->setHeaderData(i,Qt::Horizontal,header);
        ++i;
    }

    ui->tableView->setModel(reportModel);
    ui->tableView->show();
}

void FormFullReport::on_closeButton_clicked()
{
    close();
}


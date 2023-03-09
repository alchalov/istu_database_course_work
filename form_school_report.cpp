#include "form_school_report.h"
#include "ui_form_school_report.h"

#include <QDebug>
#include <QSqlError>

FormSchoolReport::FormSchoolReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSchoolReport)
{
    ui->setupUi(this);
}

FormSchoolReport::~FormSchoolReport()
{
    delete ui;
}

void FormSchoolReport::doQuery()
{
    reportModel = new QSqlQueryModel();
    QString query = QStringLiteral("SELECT FamilyName, BornYear, JoinYear, Sex, "
                                   "ClassName, ClassTeacher, TeachersPhone "
                                   "FROM students "
                                   "LEFT JOIN classes ON students.IdClass = classes.IdClass "
                                   "WHERE classes.IdSchool=%1").arg(currentSchool);
    reportModel->setQuery(query);

    QList<QString> headers = {"Ученик", "Год\nрождения", "Год\nпоступления", "Пол", "Класс", "Классный\n руководитель", "Номер\nтелефона"};
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

void FormSchoolReport::setCurrentSchool(int school)
{
    currentSchool = school;
}

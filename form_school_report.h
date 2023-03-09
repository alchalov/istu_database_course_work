#ifndef FORM_SCHOOL_REPORT_H
#define FORM_SCHOOL_REPORT_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class FormSchoolReport;
}

class FormSchoolReport : public QWidget
{
Q_OBJECT

public:
explicit FormSchoolReport(QWidget *parent = nullptr);
~FormSchoolReport();

QSqlQueryModel *reportModel;
QSqlQuery *query;

void doQuery();
void setCurrentSchool(int);

private:
Ui::FormSchoolReport *ui;

int currentSchool;
};

#endif // FORM_SCHOOL_REPORT_H

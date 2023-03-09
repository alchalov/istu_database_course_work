#ifndef FORM_FULL_REPORT_H
#define FORM_FULL_REPORT_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class FormFullReport;
}

class FormFullReport : public QWidget
{
Q_OBJECT

public:
explicit FormFullReport(QWidget *parent = nullptr);
~FormFullReport();

QSqlDatabase db;
QSqlQueryModel *fullReportModel;
QSqlQuery *query;

void setDatabase(const QString&);
void doQuery();

private slots:
void on_pushButton_clicked();

private:
Ui::FormFullReport *ui;
};

#endif // FORM_FULL_REPORT_H

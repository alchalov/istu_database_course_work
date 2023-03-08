#ifndef FORM_FULL_REPORT_H
#define FORM_FULL_REPORT_H

#include <QWidget>
#include <QSqlRelationalTableModel>

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
QSqlTableModel *fullReportModel;
void doneReport();

void setDatabase(const QString& db);

private:
Ui::FormFullReport *ui;
};

#endif // FORM_FULL_REPORT_H

#ifndef FORM_FULL_REPORT_H
#define FORM_FULL_REPORT_H

#include <QWidget>
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

QSqlQueryModel *reportModel;

void doQuery();

private slots:
void on_closeButton_clicked();

private:
Ui::FormFullReport *ui;
};

#endif // FORM_FULL_REPORT_H

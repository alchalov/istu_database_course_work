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

void FormFullReport::doneReport()
{
    fullReportModel->setTable("");

}

void FormFullReport::setDatabase(const QString &dbName)
{
    db.setDatabaseName(dbName);
}

#include "dialog_edit_student.h"
#include "ui_dialog_edit_student.h"

DialogEditStudent::DialogEditStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditStudent)
{
    ui->setupUi(this);

    mapper = new QDataWidgetMapper (this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

DialogEditStudent::~DialogEditStudent()
{
    delete ui;
}

void DialogEditStudent::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->familyNameLineEdit, 2);
    mapper->addMapping(ui->bornYearLineEdit, 3);
    mapper->addMapping(ui->joinYearLineEdit, 4);
    mapper->addMapping(ui->sexComboBox, 5);
}

void DialogEditStudent::on_applyClassButton_clicked()
{
    mapper->submit();
    close();
}


void DialogEditStudent::on_cancelClassButton_clicked()
{
    close();
}

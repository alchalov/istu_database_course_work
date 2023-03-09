#include "dialog_edit_class.h"
#include "ui_dialog_edit_class.h"

DialogEditClass::DialogEditClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditClass)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

DialogEditClass::~DialogEditClass()
{
    delete ui;
}

void DialogEditClass::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->classNameLineEdit, 2);
    mapper->addMapping(ui->classTeacherLineEdit, 3);
    mapper->addMapping(ui->teachersPhoneLineEdit, 4);
}

void DialogEditClass::on_applyClassButton_clicked()
{
    mapper->submit();
    close();
}


void DialogEditClass::on_cancelClassButton_clicked()
{
    close();
}


#include "dialog_edit_school.h"
#include "ui_dialog_edit_school.h"

DialogEditSchool::DialogEditSchool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditSchool)
{
    ui->setupUi(this);

    mapper = new QDataWidgetMapper (this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

DialogEditSchool::~DialogEditSchool()
{
    delete ui;
}

void DialogEditSchool::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->nameSchoolLineEdit, 1);
    mapper->addMapping(ui->typeSchoolComboBox, 2);
    mapper->addMapping(ui->streetLineEdit, 3);
    mapper->addMapping(ui->houseNumLineEdit, 4);

}

void DialogEditSchool::on_applyButton_clicked()
{
    mapper->submit();
    close();
}


void DialogEditSchool::on_cancelButton_clicked()
{
    close();
}

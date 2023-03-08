#ifndef DIALOG_EDIT_SCHOOL_H
#define DIALOG_EDIT_SCHOOL_H

#include <QDialog>
#include <QDataWidgetMapper>
#include <QSqlTableModel>

namespace Ui {
class DialogEditSchool;
}

class DialogEditSchool : public QDialog
{
Q_OBJECT

public:
explicit DialogEditSchool(QWidget *parent = nullptr);
~DialogEditSchool();

QDataWidgetMapper *mapper;
void setModel(QAbstractItemModel*);

private slots:
void on_applyButton_clicked();
void on_cancelButton_clicked();

private:
Ui::DialogEditSchool *ui;
};

#endif // DIALOG_EDIT_SCHOOL_H

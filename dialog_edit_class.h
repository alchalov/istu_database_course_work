#ifndef DIALOG_EDIT_CLASS_H
#define DIALOG_EDIT_CLASS_H

#include <QDialog>
#include <QDataWidgetMapper>

namespace Ui {
class DialogEditClass;
}

class DialogEditClass : public QDialog
{
Q_OBJECT

public:
explicit DialogEditClass(QWidget *parent = nullptr);
~DialogEditClass();

QDataWidgetMapper *mapper = nullptr;
void setModel(QAbstractItemModel*);

private slots:
void on_applyClassButton_clicked();
void on_cancelClassButton_clicked();

private:
Ui::DialogEditClass *ui;
};

#endif // DIALOG_EDIT_CLASS_H

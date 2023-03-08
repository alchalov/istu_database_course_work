#ifndef DIALOG_EDIT_STUDENT_H
#define DIALOG_EDIT_STUDENT_H

#include <QDialog>
#include <QDataWidgetMapper>

namespace Ui {
class DialogEditStudent;
}

class DialogEditStudent : public QDialog
{
Q_OBJECT

public:
explicit DialogEditStudent(QWidget *parent = nullptr);
~DialogEditStudent();

QDataWidgetMapper *mapper = nullptr;
void setModel(QAbstractItemModel*);

private slots:
void on_applyClassButton_clicked();
void on_cancelClassButton_clicked();

private:
Ui::DialogEditStudent *ui;
};

#endif // DIALOG_EDIT_STUDENT_H

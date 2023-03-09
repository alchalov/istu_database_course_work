#ifndef STUDENTS_WINDOW_H
#define STUDENTS_WINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>

#include "dialog_edit_student.h"

namespace Ui {
class StudentsWindow;
}

class StudentsWindow : public QMainWindow
{
Q_OBJECT

public:
explicit StudentsWindow(QWidget *parent = nullptr);
~StudentsWindow();

void setClass(int);
void setDatabase(const QString& db);
void setupWindow();

QSqlDatabase db;
QSqlRelationalTableModel *modelStudents;

private:
Ui::StudentsWindow *ui;
DialogEditStudent *dialogEditStudent;

int currentClass;

private slots:

void on_addClassButton_clicked();
void on_editClassButton_clicked();
void on_deleteClassButton_clicked();
void on_loadClassesButton_clicked();
void on_saveClassesButton_clicked();
};

#endif // STUDENTS_WINDOW_H

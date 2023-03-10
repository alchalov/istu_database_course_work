#ifndef CLASSES_WINDOW_H
#define CLASSES_WINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>

#include "students_window.h"
#include "dialog_edit_class.h"
#include "form_school_report.h"

namespace Ui {
class ClassesWindow;
}

class ClassesWindow : public QMainWindow
{
Q_OBJECT

public:
explicit ClassesWindow(QWidget *parent = nullptr);
~ClassesWindow();

void setSchool(int);
void setDatabase(const QString& db);
void setupWindow();

QSqlDatabase db;
QSqlRelationalTableModel *modelClasses;

private:
Ui::ClassesWindow *ui;
StudentsWindow *studentsWindow;
DialogEditClass *dialogEditClass;
FormSchoolReport *schoolReport;

int currentSchool;

private slots:
void on_addClassButton_clicked();
void on_editClassButton_clicked();
void on_deleteClassButton_clicked();
void on_goToStudentsButton_clicked();
void on_loadClassesButton_clicked();
void on_saveClassesButton_clicked();
void on_actionSchoolReport_triggered();
};

#endif // CLASSES_WINDOW_H

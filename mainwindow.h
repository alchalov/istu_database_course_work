#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>

#include "classes_window.h"
#include "dialog_edit_school.h"
#include "form_full_report.h"
#include "dialogabout.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();

private:
Ui::MainWindow *ui;
QSqlDatabase db;
QSqlRelationalTableModel *modelSchools;
ClassesWindow *classesWindow;
DialogEditSchool *dialogEditSchool;
DialogAbout *dialogAbout;
FormFullReport *formFullReport;

private slots:
void on_actionConnectDB_triggered();
void on_actionAbout_triggered();

void on_addSchoolButton_clicked();
void on_editSchoolButton_clicked();
void on_deleteSchoolButton_clicked();
void on_goToClassesButton_clicked();

void on_loadButton_clicked();
void on_saveButton_clicked();

void on_actionFullReport_triggered();
};
#endif // MAINWINDOW_H

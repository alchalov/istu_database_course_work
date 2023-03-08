#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>

#include "dialog_edit_school.h"

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
QSqlRelationalTableModel *model;

DialogEditSchool *dialogEditSchool;

private slots:
void on_actionAbout_triggered();
void on_actionConnectDB_triggered();

void on_addSchoolButton_clicked();
void on_editSchoolButton_clicked();
void on_deleteSchoolButton_clicked();
void on_loadButton_clicked();
void on_saveButton_clicked();
void on_revertButton_clicked();
};
#endif // MAINWINDOW_H

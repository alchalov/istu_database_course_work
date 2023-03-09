QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classes_window.cpp \
    dialog_edit_class.cpp \
    dialog_edit_school.cpp \
    dialog_edit_student.cpp \
    dialogabout.cpp \
    form_full_report.cpp \
    form_school_report.cpp \
    main.cpp \
    mainwindow.cpp \
    students_window.cpp

HEADERS += \
    classes_window.h \
    dialog_edit_class.h \
    dialog_edit_school.h \
    dialog_edit_student.h \
    dialogabout.h \
    form_full_report.h \
    form_school_report.h \
    mainwindow.h \
    students_window.h

FORMS += \
    classes_window.ui \
    dialog_edit_class.ui \
    dialog_edit_school.ui \
    dialog_edit_student.ui \
    dialogabout.ui \
    form_full_report.ui \
    form_school_report.ui \
    mainwindow.ui \
    students_window.ui

TRANSLATIONS += \
    istu_database_course_work_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

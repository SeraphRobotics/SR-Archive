#-------------------------------------------------
#
# Project created by QtCreator 2014-02-24T12:37:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    navbar.cpp \
    radio.cpp \
    hslider.cpp \
    patientdialog.cpp \
    loginpage.cpp \
    choosepatientpage.cpp \
    printerpages.cpp \
    srdialog.cpp

HEADERS  += mainwindow.h \
    navbar.h \
    radio.h \
    hslider.h \
    patientdialog.h \
    loginpage.h \
    choosepatientpage.h \
    printerpages.h \
    srdialog.h

FORMS    += mainwindow.ui \
    navbar.ui \
    verticleradio.ui \
    horizontalradio.ui \
    hslider.ui \
    patientdialog.ui \
    loginpage.ui \
    choosepatientpage.ui \
    printerpage.ui \
    srdialog.ui

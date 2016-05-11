#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T11:44:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app
#CONFIG += qaxcontainer
QT+=axcontainer

SOURCES += main.cpp\
        mainwindow.cpp \
    excelengine.cpp \
    initial.cpp

HEADERS  += mainwindow.h \
    excelengine.h \
    initial.h

FORMS    += mainwindow.ui \
    initial.ui

DISTFILES += \
    xinxi.rc
RC_FILE =\
    xinxi.rc


#-------------------------------------------------
#
# Project created by QtCreator 2021-01-08T15:04:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = armcamera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mycamera.cpp

HEADERS  += mainwindow.h \
    mycamera.h

FORMS    += mainwindow.ui

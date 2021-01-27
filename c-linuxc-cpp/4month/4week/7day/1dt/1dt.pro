#-------------------------------------------------
#
# Project created by QtCreator 2021-01-08T15:04:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1dt_armcamera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        mycamera.cpp

HEADERS  += mainwindow.h \
            mycamera.h

FORMS    += mainwindow.ui

RESOURCES +=

# 第三方头文件路径
INCLUDEPATH += \
    include
# 第三方库文件目录
LIBS += \
    lib/libjpeg.so.9.4.0 \




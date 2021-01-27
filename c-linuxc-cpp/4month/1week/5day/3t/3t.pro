#-------------------------------------------------
#
# Project created by QtCreator 2020-12-18T14:06:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3t
TEMPLATE = app


SOURCES += main.cpp\
    airca.cpp \
    contlamp.cpp \
    loginwin.cpp \
    mainwin.cpp

HEADERS  += loginwin.h \
    airca.h \
    contlamp.h \
    mainwin.h

FORMS    += loginwin.ui \
    airca.ui \
    contlamp.ui \
    mainwin.ui

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatdialog.cpp \
    chatthread.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    regwin.cpp

HEADERS += \
    chatdialog.h \
    chatthread.h \
    login.h \
    mainwindow.h \
    regwin.h

FORMS += \
    login.ui \
    mainwindow.ui \
    regwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

DISTFILES +=

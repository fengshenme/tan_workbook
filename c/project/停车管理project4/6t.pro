QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminlogin.cpp \
    allpark.cpp \
    cardsql.cpp \
    handlecard.cpp \
    main.cpp \
    mainwindow.cpp \
    mycamera.cpp \
    parkbutton.cpp \
    payrank.cpp \
    rfid.cpp \
    softkeyboard.cpp

HEADERS += \
    admin.h \
    adminlogin.h \
    allpark.h \
    cardsql.h \
    handlecard.h \
    mainwindow.h \
    mycamera.h \
    parkbutton.h \
    payrank.h \
    rfid.h \
    softkeyboard.h

FORMS += \
    admin.ui \
    adminlogin.ui \
    allpark.ui \
    handlecard.ui \
    mainwindow.ui \
    payrank.ui \
    softkeyboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

# 第三方头文件路径
INCLUDEPATH += \
    include
# 第三方库文件目录
LIBS += \
    lib/libjpeg.so.9.4.0 \

/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *centralwidget;
    QPushButton *conLampWin;
    QPushButton *airWin;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *retbt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QStringLiteral("MainWin"));
        MainWin->resize(800, 600);
        centralwidget = new QWidget(MainWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        conLampWin = new QPushButton(centralwidget);
        conLampWin->setObjectName(QStringLiteral("conLampWin"));
        conLampWin->setGeometry(QRect(430, 300, 101, 51));
        conLampWin->setStyleSheet(QLatin1String("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        airWin = new QPushButton(centralwidget);
        airWin->setObjectName(QStringLiteral("airWin"));
        airWin->setGeometry(QRect(120, 300, 101, 51));
        airWin->setStyleSheet(QLatin1String("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 130, 131, 41));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 60, 261, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 70, 131, 41));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        retbt = new QPushButton(centralwidget);
        retbt->setObjectName(QStringLiteral("retbt"));
        retbt->setGeometry(QRect(640, 70, 101, 50));
        retbt->setStyleSheet(QLatin1String("border-radius:20px; \n"
"background-color: rgb(255, 255, 255);"));
        MainWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWin->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWin->setStatusBar(statusbar);

        retranslateUi(MainWin);

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QApplication::translate("MainWin", "MainWindow", Q_NULLPTR));
        conLampWin->setText(QApplication::translate("MainWin", "\346\216\247\347\201\257", Q_NULLPTR));
        airWin->setText(QApplication::translate("MainWin", "\347\251\272\350\260\203", Q_NULLPTR));
        label_3->setText(QString());
        label->setText(QApplication::translate("MainWin", "\346\231\272\350\203\275\345\256\266\345\261\205\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        label_2->setText(QString());
        retbt->setText(QApplication::translate("MainWin", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H

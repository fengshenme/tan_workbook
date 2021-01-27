/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *refuse;
    QListWidget *listWidget;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *logout;
    QLabel *label_4;
    QLCDNumber *lcdNumber;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        refuse = new QPushButton(centralwidget);
        refuse->setObjectName(QString::fromUtf8("refuse"));
        refuse->setGeometry(QRect(11, 11, 99, 30));
        refuse->setMinimumSize(QSize(99, 30));
        refuse->setMaximumSize(QSize(99, 30));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(11, 46, 355, 399));
        listWidget->setMinimumSize(QSize(355, 399));
        listWidget->setMaximumSize(QSize(355, 399));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 410, 233, 31));
        label_2->setMinimumSize(QSize(233, 31));
        label_2->setMaximumSize(QSize(233, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 222, 222);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(390, 50, 380, 31));
        label_3->setMinimumSize(QSize(380, 31));
        label_3->setMaximumSize(QSize(380, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 222, 222);"));
        logout = new QPushButton(centralwidget);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(170, 10, 95, 28));
        logout->setMinimumSize(QSize(95, 28));
        logout->setMaximumSize(QSize(95, 28));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 10, 90, 31));
        label_4->setMinimumSize(QSize(90, 31));
        label_4->setMaximumSize(QSize(90, 31));
        label_4->setAlignment(Qt::AlignCenter);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(470, 10, 300, 31));
        lcdNumber->setMinimumSize(QSize(300, 31));
        lcdNumber->setMaximumSize(QSize(399, 31));
        lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 127);"));
        lcdNumber->setDigitCount(19);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        refuse->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\345\245\275\345\217\213", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        logout->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\214\227\344\272\254\346\227\266\351\227\264:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

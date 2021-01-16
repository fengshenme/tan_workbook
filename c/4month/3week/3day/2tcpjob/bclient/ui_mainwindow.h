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
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(390, 555);
        MainWindow->setMinimumSize(QSize(390, 555));
        MainWindow->setMaximumSize(QSize(390, 555));
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
        label_2->setGeometry(QRect(11, 457, 233, 31));
        label_2->setMinimumSize(QSize(233, 31));
        label_2->setMaximumSize(QSize(233, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 222, 222);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 10, 233, 31));
        label_3->setMinimumSize(QSize(233, 31));
        label_3->setMaximumSize(QSize(233, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 222, 222);"));
        logout = new QPushButton(centralwidget);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(260, 460, 95, 28));
        logout->setMinimumSize(QSize(95, 28));
        logout->setMaximumSize(QSize(95, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 390, 26));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

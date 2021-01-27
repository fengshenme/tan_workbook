/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *closebt;
    QPushButton *closebt_3;
    QPushButton *closebt_2;
    QPushButton *startbt;
    QPushButton *startbt_3;
    QPushButton *startbt_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 80, 395, 109));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        closebt = new QPushButton(widget);
        closebt->setObjectName(QStringLiteral("closebt"));
        closebt->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(closebt, 1, 0, 1, 1);

        closebt_3 = new QPushButton(widget);
        closebt_3->setObjectName(QStringLiteral("closebt_3"));
        closebt_3->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(closebt_3, 1, 2, 1, 1);

        closebt_2 = new QPushButton(widget);
        closebt_2->setObjectName(QStringLiteral("closebt_2"));
        closebt_2->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(closebt_2, 1, 1, 1, 1);

        startbt = new QPushButton(widget);
        startbt->setObjectName(QStringLiteral("startbt"));
        startbt->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(startbt, 0, 0, 1, 1);

        startbt_3 = new QPushButton(widget);
        startbt_3->setObjectName(QStringLiteral("startbt_3"));
        startbt_3->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(startbt_3, 0, 2, 1, 1);

        startbt_2 = new QPushButton(widget);
        startbt_2->setObjectName(QStringLiteral("startbt_2"));
        startbt_2->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(startbt_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        closebt->setText(QApplication::translate("MainWindow", "\345\205\263", 0));
        closebt_3->setText(QApplication::translate("MainWindow", "\345\205\263", 0));
        closebt_2->setText(QApplication::translate("MainWindow", "\345\205\263", 0));
        startbt->setText(QApplication::translate("MainWindow", "\345\274\200", 0));
        startbt_3->setText(QApplication::translate("MainWindow", "\345\274\200", 0));
        startbt_2->setText(QApplication::translate("MainWindow", "\345\274\200", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

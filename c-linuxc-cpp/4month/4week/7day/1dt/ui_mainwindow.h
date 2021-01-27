/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *startbt;
    QPushButton *closebt;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        startbt = new QPushButton(centralWidget);
        startbt->setObjectName(QString::fromUtf8("startbt"));
        startbt->setGeometry(QRect(440, 420, 81, 40));
        startbt->setMinimumSize(QSize(81, 40));
        startbt->setMaximumSize(QSize(81, 40));
        closebt = new QPushButton(centralWidget);
        closebt->setObjectName(QString::fromUtf8("closebt"));
        closebt->setGeometry(QRect(700, 430, 81, 40));
        closebt->setMinimumSize(QSize(81, 40));
        closebt->setMaximumSize(QSize(81, 40));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 430, 51, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startbt->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", nullptr));
        closebt->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\213\215\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

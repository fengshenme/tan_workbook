/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QWidget *centralwidget;
    QLineEdit *accoutle;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *passle;
    QPushButton *loginbt;
    QPushButton *registerBt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QString::fromUtf8("LoginWin"));
        LoginWin->resize(538, 474);
        centralwidget = new QWidget(LoginWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        accoutle = new QLineEdit(centralwidget);
        accoutle->setObjectName(QString::fromUtf8("accoutle"));
        accoutle->setGeometry(QRect(170, 90, 181, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 100, 72, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 180, 72, 31));
        passle = new QLineEdit(centralwidget);
        passle->setObjectName(QString::fromUtf8("passle"));
        passle->setGeometry(QRect(170, 170, 181, 41));
        loginbt = new QPushButton(centralwidget);
        loginbt->setObjectName(QString::fromUtf8("loginbt"));
        loginbt->setGeometry(QRect(80, 270, 93, 28));
        registerBt = new QPushButton(centralwidget);
        registerBt->setObjectName(QString::fromUtf8("registerBt"));
        registerBt->setGeometry(QRect(260, 270, 93, 28));
        LoginWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 538, 26));
        LoginWin->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWin->setStatusBar(statusbar);

        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "MainWindow", nullptr));
        label->setText(QApplication::translate("LoginWin", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201", nullptr));
        loginbt->setText(QApplication::translate("LoginWin", "\347\231\273\345\275\225", nullptr));
        registerBt->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H

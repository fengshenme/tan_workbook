/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_Login
{
public:
    QWidget *centralwidget;
    QLabel *themla;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *usele;
    QLineEdit *passwle;
    QPushButton *loginG;
    QPushButton *registB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QString::fromUtf8("LoginWin"));
        LoginWin->resize(589, 510);
        LoginWin->setWindowTitle(QString::fromUtf8("\346\231\272\350\203\275\345\256\266\345\261\205"));
        LoginWin->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(LoginWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        themla = new QLabel(centralwidget);
        themla->setObjectName(QString::fromUtf8("themla"));
        themla->setGeometry(QRect(120, 160, 71, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 210, 71, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 90, 181, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        label_3->setAlignment(Qt::AlignCenter);
        usele = new QLineEdit(centralwidget);
        usele->setObjectName(QString::fromUtf8("usele"));
        usele->setGeometry(QRect(200, 160, 241, 41));
        usele->setStyleSheet(QString::fromUtf8("border-radius:10px; \n"
"border:1px solid#000000;\n"
"\n"
""));
        passwle = new QLineEdit(centralwidget);
        passwle->setObjectName(QString::fromUtf8("passwle"));
        passwle->setGeometry(QRect(200, 210, 241, 41));
        passwle->setStyleSheet(QString::fromUtf8("border-radius:10px; \n"
"border:1px solid#000000;"));
        passwle->setEchoMode(QLineEdit::Password);
        loginG = new QPushButton(centralwidget);
        loginG->setObjectName(QString::fromUtf8("loginG"));
        loginG->setGeometry(QRect(190, 300, 111, 51));
        loginG->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        registB = new QPushButton(centralwidget);
        registB->setObjectName(QString::fromUtf8("registB"));
        registB->setGeometry(QRect(340, 300, 111, 51));
        registB->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        LoginWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 589, 26));
        LoginWin->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWin->setStatusBar(statusbar);

        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWin)
    {
        themla->setText(QApplication::translate("Login", "\350\264\246\345\217\267:", nullptr));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        label_3->setText(QApplication::translate("Login", "\346\231\272\350\203\275\345\256\266\345\261\205\347\263\273\347\273\237", nullptr));
        usele->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        passwle->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginG->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        registB->setText(QApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        Q_UNUSED(LoginWin);
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

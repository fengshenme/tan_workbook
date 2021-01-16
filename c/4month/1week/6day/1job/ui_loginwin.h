/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            LoginWin->setObjectName(QStringLiteral("LoginWin"));
        LoginWin->resize(589, 510);
        LoginWin->setWindowTitle(QString::fromUtf8("\346\231\272\350\203\275\345\256\266\345\261\205"));
        LoginWin->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(LoginWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        themla = new QLabel(centralwidget);
        themla->setObjectName(QStringLiteral("themla"));
        themla->setGeometry(QRect(120, 160, 71, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 210, 71, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 90, 181, 51));
        label_3->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        label_3->setAlignment(Qt::AlignCenter);
        usele = new QLineEdit(centralwidget);
        usele->setObjectName(QStringLiteral("usele"));
        usele->setGeometry(QRect(200, 160, 241, 41));
        usele->setStyleSheet(QLatin1String("border-radius:10px; \n"
"border:1px solid#000000;\n"
"\n"
""));
        passwle = new QLineEdit(centralwidget);
        passwle->setObjectName(QStringLiteral("passwle"));
        passwle->setGeometry(QRect(200, 210, 241, 41));
        passwle->setStyleSheet(QLatin1String("border-radius:10px; \n"
"border:1px solid#000000;"));
        passwle->setEchoMode(QLineEdit::Password);
        loginG = new QPushButton(centralwidget);
        loginG->setObjectName(QStringLiteral("loginG"));
        loginG->setGeometry(QRect(190, 300, 111, 51));
        loginG->setStyleSheet(QLatin1String("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        registB = new QPushButton(centralwidget);
        registB->setObjectName(QStringLiteral("registB"));
        registB->setGeometry(QRect(340, 300, 111, 51));
        registB->setStyleSheet(QLatin1String("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        LoginWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 589, 26));
        LoginWin->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LoginWin->setStatusBar(statusbar);

        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWin)
    {
        themla->setText(QApplication::translate("LoginWin", "\350\264\246\345\217\267:", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201:", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginWin", "\346\231\272\350\203\275\345\256\266\345\261\205\347\263\273\347\273\237", Q_NULLPTR));
        usele->setPlaceholderText(QApplication::translate("LoginWin", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", Q_NULLPTR));
        passwle->setPlaceholderText(QApplication::translate("LoginWin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        loginG->setText(QApplication::translate("LoginWin", "\347\231\273\345\275\225", Q_NULLPTR));
        registB->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214", Q_NULLPTR));
        Q_UNUSED(LoginWin);
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H

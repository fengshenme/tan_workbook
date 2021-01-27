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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *auto_login;
    QCheckBox *keep_passw;
    QPushButton *pushButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(450, 450);
        Login->setMinimumSize(QSize(450, 450));
        Login->setWindowTitle(QString::fromUtf8("IQ\350\201\212\345\244\251"));
        Login->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        themla = new QLabel(centralwidget);
        themla->setObjectName(QString::fromUtf8("themla"));
        themla->setGeometry(QRect(40, 140, 80, 40));
        themla->setMinimumSize(QSize(80, 40));
        themla->setMaximumSize(QSize(80, 40));
        themla->setStyleSheet(QString::fromUtf8("border-radius:15px; \n"
"background-color: rgb(226, 226, 226);"));
        themla->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 190, 80, 40));
        label_2->setMinimumSize(QSize(80, 40));
        label_2->setMaximumSize(QSize(80, 40));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:15px; \n"
"background-color: rgb(226, 226, 226);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 30, 100, 100));
        label_3->setMinimumSize(QSize(100, 100));
        label_3->setMaximumSize(QSize(100, 100));
        label_3->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));\n"
"border-radius:50px; "));
        label_3->setAlignment(Qt::AlignCenter);
        usele = new QLineEdit(centralwidget);
        usele->setObjectName(QString::fromUtf8("usele"));
        usele->setGeometry(QRect(130, 140, 241, 41));
        usele->setStyleSheet(QString::fromUtf8("border-radius:10px; \n"
"border:1px solid#000000;\n"
"\n"
""));
        passwle = new QLineEdit(centralwidget);
        passwle->setObjectName(QString::fromUtf8("passwle"));
        passwle->setGeometry(QRect(130, 190, 241, 41));
        passwle->setStyleSheet(QString::fromUtf8("border-radius:10px; \n"
"border:1px solid#000000;"));
        passwle->setEchoMode(QLineEdit::Password);
        loginG = new QPushButton(centralwidget);
        loginG->setObjectName(QString::fromUtf8("loginG"));
        loginG->setGeometry(QRect(120, 290, 111, 51));
        loginG->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        registB = new QPushButton(centralwidget);
        registB->setObjectName(QString::fromUtf8("registB"));
        registB->setGeometry(QRect(270, 290, 111, 51));
        registB->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 250, 291, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        auto_login = new QCheckBox(layoutWidget);
        auto_login->setObjectName(QString::fromUtf8("auto_login"));
        auto_login->setStyleSheet(QString::fromUtf8("border-radius:5px; \n"
"background-color: rgb(226, 226, 226);"));

        horizontalLayout->addWidget(auto_login);

        keep_passw = new QCheckBox(layoutWidget);
        keep_passw->setObjectName(QString::fromUtf8("keep_passw"));
        keep_passw->setStyleSheet(QString::fromUtf8("border-radius:5px; \n"
"background-color: rgb(226, 226, 226);"));

        horizontalLayout->addWidget(keep_passw);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius:6px; \n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton);

        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 26));
        Login->setMenuBar(menubar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        themla->setText(QApplication::translate("Login", "\350\264\246\345\217\267:", nullptr));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        label_3->setText(QApplication::translate("Login", "IQ\350\201\212\345\244\251", nullptr));
        usele->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        passwle->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginG->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        registB->setText(QApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        auto_login->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        keep_passw->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("Login", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        Q_UNUSED(Login);
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "softkeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_AdminLogin
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
    QPushButton *softkeyboard;
    SoftKeyBoard *skboard;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *auto_login;
    QPushButton *pushButton;

    void setupUi(QMainWindow *AdminLogin)
    {
        if (AdminLogin->objectName().isEmpty())
            AdminLogin->setObjectName(QString::fromUtf8("AdminLogin"));
        AdminLogin->resize(800, 480);
        AdminLogin->setMinimumSize(QSize(800, 480));
        AdminLogin->setMaximumSize(QSize(800, 480));
        AdminLogin->setWindowTitle(QString::fromUtf8("IQ\350\201\212\345\244\251"));
        AdminLogin->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(AdminLogin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        themla = new QLabel(centralwidget);
        themla->setObjectName(QString::fromUtf8("themla"));
        themla->setGeometry(QRect(170, 100, 80, 40));
        themla->setMinimumSize(QSize(80, 40));
        themla->setMaximumSize(QSize(80, 40));
        themla->setStyleSheet(QString::fromUtf8("border-radius:15px; \n"
"background-color: rgb(226, 226, 226);"));
        themla->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 150, 80, 40));
        label_2->setMinimumSize(QSize(80, 40));
        label_2->setMaximumSize(QSize(80, 40));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:15px; \n"
"background-color: rgb(226, 226, 226);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 0, 100, 100));
        label_3->setMinimumSize(QSize(100, 100));
        label_3->setMaximumSize(QSize(100, 100));
        label_3->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));\n"
"border-radius:50px; "));
        label_3->setAlignment(Qt::AlignCenter);
        usele = new QLineEdit(centralwidget);
        usele->setObjectName(QString::fromUtf8("usele"));
        usele->setGeometry(QRect(260, 100, 241, 41));
        usele->setStyleSheet(QString::fromUtf8("border-radius:10px; \n"
"border:1px solid#000000;\n"
"\n"
""));
        passwle = new QLineEdit(centralwidget);
        passwle->setObjectName(QString::fromUtf8("passwle"));
        passwle->setGeometry(QRect(260, 150, 241, 41));
        passwle->setStyleSheet(QString::fromUtf8("border-radius:10px; \n"
"border:1px solid#000000;"));
        passwle->setEchoMode(QLineEdit::Password);
        loginG = new QPushButton(centralwidget);
        loginG->setObjectName(QString::fromUtf8("loginG"));
        loginG->setGeometry(QRect(220, 200, 111, 51));
        loginG->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        registB = new QPushButton(centralwidget);
        registB->setObjectName(QString::fromUtf8("registB"));
        registB->setGeometry(QRect(370, 200, 111, 51));
        registB->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        softkeyboard = new QPushButton(centralwidget);
        softkeyboard->setObjectName(QString::fromUtf8("softkeyboard"));
        softkeyboard->setGeometry(QRect(510, 110, 31, 28));
        softkeyboard->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/softkeyboard.jpg);"));
        skboard = new SoftKeyBoard(centralwidget);
        skboard->setObjectName(QString::fromUtf8("skboard"));
        skboard->setGeometry(QRect(90, 260, 561, 211));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(540, 190, 83, 55));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        auto_login = new QCheckBox(widget);
        auto_login->setObjectName(QString::fromUtf8("auto_login"));
        auto_login->setStyleSheet(QString::fromUtf8("border-radius:5px; \n"
"background-color: rgb(226, 226, 226);"));

        verticalLayout->addWidget(auto_login);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius:6px; \n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton);

        AdminLogin->setCentralWidget(centralwidget);

        retranslateUi(AdminLogin);

        QMetaObject::connectSlotsByName(AdminLogin);
    } // setupUi

    void retranslateUi(QMainWindow *AdminLogin)
    {
        themla->setText(QCoreApplication::translate("AdminLogin", "\350\264\246\345\217\267:", nullptr));
        label_2->setText(QCoreApplication::translate("AdminLogin", "\345\257\206\347\240\201:", nullptr));
        label_3->setText(QCoreApplication::translate("AdminLogin", "\345\201\234\350\275\246\347\256\241\347\220\206", nullptr));
        usele->setPlaceholderText(QCoreApplication::translate("AdminLogin", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        passwle->setPlaceholderText(QCoreApplication::translate("AdminLogin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginG->setText(QCoreApplication::translate("AdminLogin", "\347\231\273\345\275\225", nullptr));
        registB->setText(QCoreApplication::translate("AdminLogin", "\346\263\250\345\206\214", nullptr));
        softkeyboard->setText(QString());
        auto_login->setText(QCoreApplication::translate("AdminLogin", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        pushButton->setText(QCoreApplication::translate("AdminLogin", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        Q_UNUSED(AdminLogin);
    } // retranslateUi

};

namespace Ui {
    class AdminLogin: public Ui_AdminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H

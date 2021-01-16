/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QPushButton *softkeyboard;
    SoftKeyBoard *skboard;
    QPushButton *pushButton;

    void setupUi(QMainWindow *AdminLogin)
    {
        if (AdminLogin->objectName().isEmpty())
            AdminLogin->setObjectName(QStringLiteral("AdminLogin"));
        AdminLogin->resize(800, 480);
        AdminLogin->setMinimumSize(QSize(800, 480));
        AdminLogin->setMaximumSize(QSize(800, 480));
        AdminLogin->setWindowTitle(QString::fromUtf8("IQ\350\201\212\345\244\251"));
        AdminLogin->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(AdminLogin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        themla = new QLabel(centralwidget);
        themla->setObjectName(QStringLiteral("themla"));
        themla->setGeometry(QRect(170, 100, 80, 40));
        themla->setMinimumSize(QSize(80, 40));
        themla->setMaximumSize(QSize(80, 40));
        themla->setStyleSheet(QLatin1String("border-radius:15px; \n"
"background-color: rgb(226, 226, 226);"));
        themla->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 150, 80, 40));
        label_2->setMinimumSize(QSize(80, 40));
        label_2->setMaximumSize(QSize(80, 40));
        label_2->setStyleSheet(QLatin1String("border-radius:15px; \n"
"background-color: rgb(226, 226, 226);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 0, 100, 100));
        label_3->setMinimumSize(QSize(100, 100));
        label_3->setMaximumSize(QSize(100, 100));
        label_3->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));\n"
"border-radius:50px; "));
        label_3->setAlignment(Qt::AlignCenter);
        usele = new QLineEdit(centralwidget);
        usele->setObjectName(QStringLiteral("usele"));
        usele->setGeometry(QRect(260, 100, 241, 41));
        usele->setStyleSheet(QLatin1String("border-radius:10px; \n"
"border:1px solid#000000;\n"
"\n"
""));
        passwle = new QLineEdit(centralwidget);
        passwle->setObjectName(QStringLiteral("passwle"));
        passwle->setGeometry(QRect(260, 150, 241, 41));
        passwle->setStyleSheet(QLatin1String("border-radius:10px; \n"
"border:1px solid#000000;"));
        passwle->setEchoMode(QLineEdit::Password);
        loginG = new QPushButton(centralwidget);
        loginG->setObjectName(QStringLiteral("loginG"));
        loginG->setGeometry(QRect(310, 200, 111, 51));
        loginG->setStyleSheet(QLatin1String("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        softkeyboard = new QPushButton(centralwidget);
        softkeyboard->setObjectName(QStringLiteral("softkeyboard"));
        softkeyboard->setGeometry(QRect(510, 110, 31, 28));
        softkeyboard->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/softkeyboard.jpg);"));
        skboard = new SoftKeyBoard(centralwidget);
        skboard->setObjectName(QStringLiteral("skboard"));
        skboard->setGeometry(QRect(90, 260, 561, 211));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 50, 50));
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/prev.jpg);"));
        AdminLogin->setCentralWidget(centralwidget);

        retranslateUi(AdminLogin);

        QMetaObject::connectSlotsByName(AdminLogin);
    } // setupUi

    void retranslateUi(QMainWindow *AdminLogin)
    {
        themla->setText(QApplication::translate("AdminLogin", "\350\264\246\345\217\267:", 0));
        label_2->setText(QApplication::translate("AdminLogin", "\345\257\206\347\240\201:", 0));
        label_3->setText(QApplication::translate("AdminLogin", "\345\201\234\350\275\246\347\256\241\347\220\206", 0));
        usele->setPlaceholderText(QApplication::translate("AdminLogin", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", 0));
        passwle->setPlaceholderText(QApplication::translate("AdminLogin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        loginG->setText(QApplication::translate("AdminLogin", "\347\231\273\345\275\225", 0));
        softkeyboard->setText(QString());
        pushButton->setText(QApplication::translate("AdminLogin", "\350\277\224\345\233\236", 0));
        Q_UNUSED(AdminLogin);
    } // retranslateUi

};

namespace Ui {
    class AdminLogin: public Ui_AdminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H

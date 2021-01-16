/********************************************************************************
** Form generated from reading UI file 'registerwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIN_H
#define UI_REGISTERWIN_H

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

class Ui_RegisterWin
{
public:
    QWidget *centralwidget;
    QLineEdit *accountLe;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *passLe;
    QLineEdit *passLe2;
    QLabel *label_3;
    QPushButton *registerBt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWin)
    {
        if (RegisterWin->objectName().isEmpty())
            RegisterWin->setObjectName(QString::fromUtf8("RegisterWin"));
        RegisterWin->resize(414, 492);
        centralwidget = new QWidget(RegisterWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        accountLe = new QLineEdit(centralwidget);
        accountLe->setObjectName(QString::fromUtf8("accountLe"));
        accountLe->setGeometry(QRect(130, 100, 161, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 110, 72, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 170, 72, 15));
        passLe = new QLineEdit(centralwidget);
        passLe->setObjectName(QString::fromUtf8("passLe"));
        passLe->setGeometry(QRect(130, 160, 161, 31));
        passLe2 = new QLineEdit(centralwidget);
        passLe2->setObjectName(QString::fromUtf8("passLe2"));
        passLe2->setGeometry(QRect(130, 220, 161, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 230, 72, 15));
        registerBt = new QPushButton(centralwidget);
        registerBt->setObjectName(QString::fromUtf8("registerBt"));
        registerBt->setGeometry(QRect(140, 280, 101, 41));
        RegisterWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 414, 26));
        RegisterWin->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RegisterWin->setStatusBar(statusbar);

        retranslateUi(RegisterWin);

        QMetaObject::connectSlotsByName(RegisterWin);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWin)
    {
        RegisterWin->setWindowTitle(QApplication::translate("RegisterWin", "MainWindow", nullptr));
        label->setText(QApplication::translate("RegisterWin", "\346\226\260\350\264\246\345\217\267:", nullptr));
        label_2->setText(QApplication::translate("RegisterWin", "\345\257\206\347\240\201:", nullptr));
        label_3->setText(QApplication::translate("RegisterWin", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        registerBt->setText(QApplication::translate("RegisterWin", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWin: public Ui_RegisterWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIN_H

/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwin
{
public:
    QWidget *centralWidget;
    QLineEdit *usrle;
    QLineEdit *passwdle;
    QLabel *label;
    QLabel *label_2;
    QPushButton *loginbt;
    QPushButton *regbt;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *loginwin)
    {
        if (loginwin->objectName().isEmpty())
            loginwin->setObjectName(QStringLiteral("loginwin"));
        loginwin->resize(400, 300);
        centralWidget = new QWidget(loginwin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        usrle = new QLineEdit(centralWidget);
        usrle->setObjectName(QStringLiteral("usrle"));
        usrle->setGeometry(QRect(160, 100, 113, 20));
        passwdle = new QLineEdit(centralWidget);
        passwdle->setObjectName(QStringLiteral("passwdle"));
        passwdle->setGeometry(QRect(160, 140, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 100, 61, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 140, 54, 12));
        loginbt = new QPushButton(centralWidget);
        loginbt->setObjectName(QStringLiteral("loginbt"));
        loginbt->setGeometry(QRect(80, 180, 75, 23));
        regbt = new QPushButton(centralWidget);
        regbt->setObjectName(QStringLiteral("regbt"));
        regbt->setGeometry(QRect(210, 180, 75, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 20, 151, 41));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        loginwin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(loginwin);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        loginwin->setMenuBar(menuBar);
        mainToolBar = new QToolBar(loginwin);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        loginwin->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(loginwin);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        loginwin->setStatusBar(statusBar);

        retranslateUi(loginwin);

        QMetaObject::connectSlotsByName(loginwin);
    } // setupUi

    void retranslateUi(QMainWindow *loginwin)
    {
        loginwin->setWindowTitle(QApplication::translate("loginwin", "loginwin", 0));
        label->setText(QApplication::translate("loginwin", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("loginwin", "\345\257\206\347\240\201\357\274\232", 0));
        loginbt->setText(QApplication::translate("loginwin", "\347\231\273\345\275\225", 0));
        regbt->setText(QApplication::translate("loginwin", "\346\263\250\345\206\214", 0));
        label_3->setText(QApplication::translate("loginwin", "\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\350\203\275\347\262\244\345\265\214\345\256\266\345\261\205\347\263\273\347\273\237", 0));
    } // retranslateUi

};

namespace Ui {
    class loginwin: public Ui_loginwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H

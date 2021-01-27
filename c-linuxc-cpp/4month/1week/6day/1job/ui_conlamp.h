/********************************************************************************
** Form generated from reading UI file 'conlamp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONLAMP_H
#define UI_CONLAMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConLamp
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *switchON;
    QPushButton *lampBu;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConLamp)
    {
        if (ConLamp->objectName().isEmpty())
            ConLamp->setObjectName(QStringLiteral("ConLamp"));
        ConLamp->resize(800, 600);
        centralwidget = new QWidget(ConLamp);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 91, 41));
        pushButton->setStyleSheet(QLatin1String("border-radius:20px; \n"
"background-color: rgb(255, 255, 255);"));
        switchON = new QPushButton(centralwidget);
        switchON->setObjectName(QStringLiteral("switchON"));
        switchON->setGeometry(QRect(330, 450, 80, 80));
        QFont font;
        font.setPointSize(16);
        switchON->setFont(font);
        switchON->setStyleSheet(QLatin1String("border-radius:40px; \n"
"background-color: rgb(217, 217, 217);"));
        lampBu = new QPushButton(centralwidget);
        lampBu->setObjectName(QStringLiteral("lampBu"));
        lampBu->setGeometry(QRect(160, 10, 400, 400));
        lampBu->setStyleSheet(QStringLiteral("background-color: rgb(217, 217, 217);border-radius:200px;"));
        ConLamp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConLamp);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ConLamp->setMenuBar(menubar);
        statusbar = new QStatusBar(ConLamp);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ConLamp->setStatusBar(statusbar);

        retranslateUi(ConLamp);

        QMetaObject::connectSlotsByName(ConLamp);
    } // setupUi

    void retranslateUi(QMainWindow *ConLamp)
    {
        ConLamp->setWindowTitle(QApplication::translate("ConLamp", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ConLamp", "\350\277\224\345\233\236", Q_NULLPTR));
        switchON->setText(QApplication::translate("ConLamp", "\345\205\263", Q_NULLPTR));
        lampBu->setText(QApplication::translate("ConLamp", "LED\347\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConLamp: public Ui_ConLamp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONLAMP_H

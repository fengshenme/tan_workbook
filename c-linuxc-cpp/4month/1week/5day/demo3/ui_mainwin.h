/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwin
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *retbt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainwin)
    {
        if (mainwin->objectName().isEmpty())
            mainwin->setObjectName(QStringLiteral("mainwin"));
        mainwin->resize(800, 600);
        centralwidget = new QWidget(mainwin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 30, 261, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 270, 101, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 270, 101, 51));
        retbt = new QPushButton(centralwidget);
        retbt->setObjectName(QStringLiteral("retbt"));
        retbt->setGeometry(QRect(640, 40, 101, 51));
        mainwin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        mainwin->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mainwin->setStatusBar(statusbar);

        retranslateUi(mainwin);

        QMetaObject::connectSlotsByName(mainwin);
    } // setupUi

    void retranslateUi(QMainWindow *mainwin)
    {
        mainwin->setWindowTitle(QApplication::translate("mainwin", "MainWindow", 0));
        label->setText(QApplication::translate("mainwin", "\346\231\272\350\203\275\345\256\266\345\261\205\344\270\273\347\225\214\351\235\242", 0));
        pushButton->setText(QApplication::translate("mainwin", "\347\251\272\350\260\203", 0));
        pushButton_2->setText(QApplication::translate("mainwin", "\346\216\247\347\201\257", 0));
        retbt->setText(QApplication::translate("mainwin", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwin: public Ui_mainwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H

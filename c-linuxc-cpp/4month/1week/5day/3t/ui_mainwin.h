/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
    QLabel *label_2;
    QLabel *label_3;
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
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 20, 131, 41));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 131, 41));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        mainwin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        mainwin->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mainwin->setStatusBar(statusbar);

        retranslateUi(mainwin);

        QMetaObject::connectSlotsByName(mainwin);
    } // setupUi

    void retranslateUi(QMainWindow *mainwin)
    {
        mainwin->setWindowTitle(QApplication::translate("mainwin", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("mainwin", "\346\231\272\350\203\275\345\256\266\345\261\205\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mainwin", "\347\251\272\350\260\203", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mainwin", "\346\216\247\347\201\257", Q_NULLPTR));
        retbt->setText(QApplication::translate("mainwin", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainwin: public Ui_mainwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H

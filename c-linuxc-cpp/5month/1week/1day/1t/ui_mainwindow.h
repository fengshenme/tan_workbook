/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *portcbox;
    QLabel *label_2;
    QComboBox *portcbox_2;
    QLabel *label_3;
    QComboBox *portcbox_3;
    QLabel *label_4;
    QComboBox *portcbox_4;
    QLabel *label_5;
    QComboBox *portcbox_5;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 60, 271, 221));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(81, 31));
        label->setMaximumSize(QSize(81, 31));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        portcbox = new QComboBox(widget);
        portcbox->setObjectName(QString::fromUtf8("portcbox"));
        portcbox->setMinimumSize(QSize(161, 31));
        portcbox->setMaximumSize(QSize(161, 31));

        gridLayout->addWidget(portcbox, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(81, 31));
        label_2->setMaximumSize(QSize(81, 31));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        portcbox_2 = new QComboBox(widget);
        portcbox_2->setObjectName(QString::fromUtf8("portcbox_2"));
        portcbox_2->setMinimumSize(QSize(161, 31));
        portcbox_2->setMaximumSize(QSize(161, 31));

        gridLayout->addWidget(portcbox_2, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(81, 31));
        label_3->setMaximumSize(QSize(81, 31));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        portcbox_3 = new QComboBox(widget);
        portcbox_3->setObjectName(QString::fromUtf8("portcbox_3"));
        portcbox_3->setMinimumSize(QSize(161, 31));
        portcbox_3->setMaximumSize(QSize(161, 31));

        gridLayout->addWidget(portcbox_3, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(81, 31));
        label_4->setMaximumSize(QSize(81, 31));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        portcbox_4 = new QComboBox(widget);
        portcbox_4->setObjectName(QString::fromUtf8("portcbox_4"));
        portcbox_4->setMinimumSize(QSize(161, 31));
        portcbox_4->setMaximumSize(QSize(161, 31));

        gridLayout->addWidget(portcbox_4, 3, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(81, 31));
        label_5->setMaximumSize(QSize(81, 31));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        portcbox_5 = new QComboBox(widget);
        portcbox_5->setObjectName(QString::fromUtf8("portcbox_5"));
        portcbox_5->setMinimumSize(QSize(161, 31));
        portcbox_5->setMaximumSize(QSize(161, 31));

        gridLayout->addWidget(portcbox_5, 4, 1, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(310, 80, 122, 167));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(71, 21));
        label_6->setMaximumSize(QSize(71, 21));

        verticalLayout->addWidget(label_6);

        checkBox = new QCheckBox(widget1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(120, 41));
        checkBox->setMaximumSize(QSize(120, 41));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(widget1);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(120, 41));
        checkBox_2->setMaximumSize(QSize(120, 41));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(widget1);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setMinimumSize(QSize(120, 41));
        checkBox_3->setMaximumSize(QSize(120, 41));

        verticalLayout->addWidget(checkBox_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247:", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "DTR/DSR", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "RTS/CTS", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "XON/XOFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

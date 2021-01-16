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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QComboBox *portcbox;
    QLabel *label_3;
    QComboBox *portcbox_2;
    QLabel *label_5;
    QLabel *label_4;
    QComboBox *portcbox_3;
    QComboBox *portcbox_4;
    QComboBox *portcbox_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(410, 80, 122, 167));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(71, 21));
        label_6->setMaximumSize(QSize(71, 21));

        verticalLayout->addWidget(label_6);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(120, 41));
        checkBox->setMaximumSize(QSize(120, 41));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(120, 41));
        checkBox_2->setMaximumSize(QSize(120, 41));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setMinimumSize(QSize(120, 41));
        checkBox_3->setMaximumSize(QSize(120, 41));

        verticalLayout->addWidget(checkBox_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 360, 111, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(28, 79, 81, 31));
        label->setMinimumSize(QSize(81, 31));
        label->setMaximumSize(QSize(81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(28, 128, 81, 31));
        label_2->setMinimumSize(QSize(81, 31));
        label_2->setMaximumSize(QSize(81, 31));
        portcbox = new QComboBox(centralwidget);
        portcbox->setObjectName(QString::fromUtf8("portcbox"));
        portcbox->setGeometry(QRect(126, 79, 220, 31));
        portcbox->setMinimumSize(QSize(220, 31));
        portcbox->setMaximumSize(QSize(220, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(28, 177, 81, 31));
        label_3->setMinimumSize(QSize(81, 31));
        label_3->setMaximumSize(QSize(81, 31));
        portcbox_2 = new QComboBox(centralwidget);
        portcbox_2->setObjectName(QString::fromUtf8("portcbox_2"));
        portcbox_2->setGeometry(QRect(126, 128, 220, 31));
        portcbox_2->setMinimumSize(QSize(220, 31));
        portcbox_2->setMaximumSize(QSize(220, 31));
        portcbox_2->setEditable(false);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(28, 275, 81, 31));
        label_5->setMinimumSize(QSize(81, 31));
        label_5->setMaximumSize(QSize(81, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(28, 226, 81, 31));
        label_4->setMinimumSize(QSize(81, 31));
        label_4->setMaximumSize(QSize(81, 31));
        portcbox_3 = new QComboBox(centralwidget);
        portcbox_3->setObjectName(QString::fromUtf8("portcbox_3"));
        portcbox_3->setGeometry(QRect(126, 177, 220, 31));
        portcbox_3->setMinimumSize(QSize(220, 31));
        portcbox_3->setMaximumSize(QSize(220, 31));
        portcbox_4 = new QComboBox(centralwidget);
        portcbox_4->setObjectName(QString::fromUtf8("portcbox_4"));
        portcbox_4->setGeometry(QRect(126, 226, 220, 31));
        portcbox_4->setMinimumSize(QSize(220, 31));
        portcbox_4->setMaximumSize(QSize(220, 31));
        portcbox_5 = new QComboBox(centralwidget);
        portcbox_5->setObjectName(QString::fromUtf8("portcbox_5"));
        portcbox_5->setGeometry(QRect(126, 275, 220, 31));
        portcbox_5->setMinimumSize(QSize(220, 31));
        portcbox_5->setMaximumSize(QSize(220, 31));
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
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247:", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "DTR/DSR", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "RTS/CTS", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "XON/XOFF", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *prevbt;
    QPushButton *nextpt;
    QLabel *label_10;
    QPushButton *adminloginbt;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *weather;
    QLabel *label;
    QLCDNumber *lcdTime;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_6;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *parkingbt1;
    QPushButton *parkingbt2;
    QPushButton *parkingbt3;
    QPushButton *parkingbt4;
    QPushButton *parkingbt5;
    QPushButton *parkingbt6;
    QPushButton *parkingbt7;
    QPushButton *parkingbt8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(470, 10, 320, 240));
        widget->setMinimumSize(QSize(320, 240));
        widget->setMaximumSize(QSize(320, 240));
        widget->setContextMenuPolicy(Qt::NoContextMenu);
        prevbt = new QPushButton(centralwidget);
        prevbt->setObjectName(QString::fromUtf8("prevbt"));
        prevbt->setGeometry(QRect(0, 140, 130, 90));
        prevbt->setMinimumSize(QSize(130, 90));
        prevbt->setMaximumSize(QSize(130, 90));
        prevbt->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/prev.jpg);\n"
""));
        nextpt = new QPushButton(centralwidget);
        nextpt->setObjectName(QString::fromUtf8("nextpt"));
        nextpt->setGeometry(QRect(142, 140, 130, 90));
        nextpt->setMinimumSize(QSize(130, 90));
        nextpt->setMaximumSize(QSize(130, 90));
        nextpt->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/new/prefix1/img/next.jpg);"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(60, 100, 121, 41));
        label_10->setAlignment(Qt::AlignCenter);
        adminloginbt = new QPushButton(centralwidget);
        adminloginbt->setObjectName(QString::fromUtf8("adminloginbt"));
        adminloginbt->setGeometry(QRect(380, 10, 80, 80));
        adminloginbt->setMinimumSize(QSize(80, 80));
        adminloginbt->setMaximumSize(QSize(80, 80));
        adminloginbt->setStyleSheet(QString::fromUtf8("border-radius:39px;border:1px solid#BFBFBF; background-color: rgb(222, 222, 222);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 359, 82));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 36));
        label_2->setMaximumSize(QSize(50, 36));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        weather = new QLabel(layoutWidget);
        weather->setObjectName(QString::fromUtf8("weather"));
        weather->setMinimumSize(QSize(300, 36));
        weather->setMaximumSize(QSize(300, 36));
        weather->setContextMenuPolicy(Qt::NoContextMenu);
        weather->setLayoutDirection(Qt::LeftToRight);
        weather->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(weather, 0, 1, 2, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 36));
        label->setMaximumSize(QSize(50, 36));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 2, 1);

        lcdTime = new QLCDNumber(layoutWidget);
        lcdTime->setObjectName(QString::fromUtf8("lcdTime"));
        lcdTime->setMinimumSize(QSize(300, 30));
        lcdTime->setMaximumSize(QSize(300, 30));
        lcdTime->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 127);"));
        lcdTime->setDigitCount(19);

        gridLayout->addWidget(lcdTime, 2, 1, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(280, 110, 171, 124));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(81, 36));
        label_8->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(81, 36));
        label_4->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(81, 36));
        label_5->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(81, 36));
        label_9->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_9, 2, 1, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(81, 36));
        label_7->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(81, 36));
        label_6->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_6, 1, 1, 1, 1);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 270, 791, 202));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        parkingbt1 = new QPushButton(layoutWidget2);
        parkingbt1->setObjectName(QString::fromUtf8("parkingbt1"));
        parkingbt1->setMinimumSize(QSize(90, 200));
        parkingbt1->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt1);

        parkingbt2 = new QPushButton(layoutWidget2);
        parkingbt2->setObjectName(QString::fromUtf8("parkingbt2"));
        parkingbt2->setMinimumSize(QSize(90, 200));
        parkingbt2->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt2);

        parkingbt3 = new QPushButton(layoutWidget2);
        parkingbt3->setObjectName(QString::fromUtf8("parkingbt3"));
        parkingbt3->setMinimumSize(QSize(90, 200));
        parkingbt3->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt3);

        parkingbt4 = new QPushButton(layoutWidget2);
        parkingbt4->setObjectName(QString::fromUtf8("parkingbt4"));
        parkingbt4->setMinimumSize(QSize(90, 200));
        parkingbt4->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt4);

        parkingbt5 = new QPushButton(layoutWidget2);
        parkingbt5->setObjectName(QString::fromUtf8("parkingbt5"));
        parkingbt5->setMinimumSize(QSize(90, 200));
        parkingbt5->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt5);

        parkingbt6 = new QPushButton(layoutWidget2);
        parkingbt6->setObjectName(QString::fromUtf8("parkingbt6"));
        parkingbt6->setMinimumSize(QSize(90, 200));
        parkingbt6->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt6);

        parkingbt7 = new QPushButton(layoutWidget2);
        parkingbt7->setObjectName(QString::fromUtf8("parkingbt7"));
        parkingbt7->setMinimumSize(QSize(90, 200));
        parkingbt7->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt7);

        parkingbt8 = new QPushButton(layoutWidget2);
        parkingbt8->setObjectName(QString::fromUtf8("parkingbt8"));
        parkingbt8->setMinimumSize(QSize(90, 200));
        parkingbt8->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt8);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        prevbt->setText(QCoreApplication::translate("MainWindow", "\344\270\212\345\214\272", nullptr));
        nextpt->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\214\272", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\347\233\256\345\211\215\344\275\215\347\275\256:d\345\214\272", nullptr));
        adminloginbt->setText(QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\345\244\204", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224:", nullptr));
        weather->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\346\230\276\347\244\272\345\214\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\350\264\271\347\224\250:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\211\251\344\275\231\350\275\246\344\275\215:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\275\246\344\275\215\346\225\260", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "10\345\205\203", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\346\227\266\351\227\264:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "2.5h", nullptr));
        parkingbt1->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt2->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt3->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt4->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt5->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt6->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt7->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt8->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

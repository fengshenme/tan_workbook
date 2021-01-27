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
    QPushButton *pushButton_11;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *weather;
    QLabel *label;
    QLCDNumber *lcdTime;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_6;
    QWidget *widget3;
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
        prevbt->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/prev.jpg);\n"
""));
        nextpt = new QPushButton(centralwidget);
        nextpt->setObjectName(QString::fromUtf8("nextpt"));
        nextpt->setGeometry(QRect(142, 140, 130, 90));
        nextpt->setMinimumSize(QSize(130, 90));
        nextpt->setMaximumSize(QSize(130, 90));
        nextpt->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/next.jpg);"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(80, 110, 91, 31));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(380, 10, 80, 80));
        pushButton_11->setMinimumSize(QSize(80, 80));
        pushButton_11->setMaximumSize(QSize(80, 80));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-radius:39px;border:1px solid#BFBFBF; background-color: rgb(222, 222, 222);"));
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 10, 359, 82));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 36));
        label_2->setMaximumSize(QSize(50, 36));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        weather = new QLabel(widget1);
        weather->setObjectName(QString::fromUtf8("weather"));
        weather->setMinimumSize(QSize(300, 36));
        weather->setMaximumSize(QSize(300, 36));
        weather->setContextMenuPolicy(Qt::NoContextMenu);
        weather->setLayoutDirection(Qt::LeftToRight);
        weather->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(weather, 0, 1, 2, 1);

        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 36));
        label->setMaximumSize(QSize(50, 36));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 2, 1);

        lcdTime = new QLCDNumber(widget1);
        lcdTime->setObjectName(QString::fromUtf8("lcdTime"));
        lcdTime->setMinimumSize(QSize(300, 30));
        lcdTime->setMaximumSize(QSize(300, 30));
        lcdTime->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 127);"));
        lcdTime->setDigitCount(19);

        gridLayout->addWidget(lcdTime, 2, 1, 1, 1);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(280, 110, 171, 124));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(81, 36));
        label_8->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(81, 36));
        label_4->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(widget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(81, 36));
        label_5->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_9 = new QLabel(widget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(81, 36));
        label_9->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_9, 2, 1, 1, 1);

        label_7 = new QLabel(widget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(81, 36));
        label_7->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_6 = new QLabel(widget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(81, 36));
        label_6->setMaximumSize(QSize(81, 36));

        gridLayout_2->addWidget(label_6, 1, 1, 1, 1);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(0, 270, 791, 202));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        parkingbt1 = new QPushButton(widget3);
        parkingbt1->setObjectName(QString::fromUtf8("parkingbt1"));
        parkingbt1->setMinimumSize(QSize(90, 200));
        parkingbt1->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt1);

        parkingbt2 = new QPushButton(widget3);
        parkingbt2->setObjectName(QString::fromUtf8("parkingbt2"));
        parkingbt2->setMinimumSize(QSize(90, 200));
        parkingbt2->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt2);

        parkingbt3 = new QPushButton(widget3);
        parkingbt3->setObjectName(QString::fromUtf8("parkingbt3"));
        parkingbt3->setMinimumSize(QSize(90, 200));
        parkingbt3->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt3);

        parkingbt4 = new QPushButton(widget3);
        parkingbt4->setObjectName(QString::fromUtf8("parkingbt4"));
        parkingbt4->setMinimumSize(QSize(90, 200));
        parkingbt4->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt4);

        parkingbt5 = new QPushButton(widget3);
        parkingbt5->setObjectName(QString::fromUtf8("parkingbt5"));
        parkingbt5->setMinimumSize(QSize(90, 200));
        parkingbt5->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt5);

        parkingbt6 = new QPushButton(widget3);
        parkingbt6->setObjectName(QString::fromUtf8("parkingbt6"));
        parkingbt6->setMinimumSize(QSize(90, 200));
        parkingbt6->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt6);

        parkingbt7 = new QPushButton(widget3);
        parkingbt7->setObjectName(QString::fromUtf8("parkingbt7"));
        parkingbt7->setMinimumSize(QSize(90, 200));
        parkingbt7->setMaximumSize(QSize(90, 200));

        horizontalLayout->addWidget(parkingbt7);

        parkingbt8 = new QPushButton(widget3);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        prevbt->setText(QApplication::translate("MainWindow", "\344\270\212\345\214\272", nullptr));
        nextpt->setText(QApplication::translate("MainWindow", "\344\270\213\345\214\272", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\347\216\260\345\234\250\346\230\257:d\345\214\272", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\244\204", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224:", nullptr));
        weather->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224\346\230\276\347\244\272\345\214\272", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\350\264\271\347\224\250:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\211\251\344\275\231\350\275\246\344\275\215:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\350\275\246\344\275\215\346\225\260", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "10\345\205\203", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\346\227\266\351\227\264:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "2.5h", nullptr));
        parkingbt1->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt2->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt3->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt4->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt5->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt6->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt7->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
        parkingbt8->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

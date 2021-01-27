/********************************************************************************
** Form generated from reading UI file 'allpark.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLPARK_H
#define UI_ALLPARK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllPark
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *findAll;
    QPushButton *prevBt;

    void setupUi(QMainWindow *AllPark)
    {
        if (AllPark->objectName().isEmpty())
            AllPark->setObjectName(QString::fromUtf8("AllPark"));
        AllPark->resize(800, 480);
        AllPark->setMinimumSize(QSize(800, 480));
        AllPark->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(AllPark);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(5, 5, 640, 469));
        tableWidget->setMinimumSize(QSize(640, 469));
        tableWidget->setMaximumSize(QSize(640, 469));
        findAll = new QPushButton(centralwidget);
        findAll->setObjectName(QString::fromUtf8("findAll"));
        findAll->setGeometry(QRect(650, 10, 130, 39));
        findAll->setMinimumSize(QSize(130, 39));
        findAll->setMaximumSize(QSize(130, 39));
        prevBt = new QPushButton(centralwidget);
        prevBt->setObjectName(QString::fromUtf8("prevBt"));
        prevBt->setGeometry(QRect(660, 410, 131, 61));
        prevBt->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/prev.jpg);"));
        AllPark->setCentralWidget(centralwidget);

        retranslateUi(AllPark);

        QMetaObject::connectSlotsByName(AllPark);
    } // setupUi

    void retranslateUi(QMainWindow *AllPark)
    {
        AllPark->setWindowTitle(QCoreApplication::translate("AllPark", "MainWindow", nullptr));
        findAll->setText(QCoreApplication::translate("AllPark", "\346\237\245\350\257\242\345\205\250\351\203\250", nullptr));
        prevBt->setText(QCoreApplication::translate("AllPark", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllPark: public Ui_AllPark {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLPARK_H

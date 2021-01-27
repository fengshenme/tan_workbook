/********************************************************************************
** Form generated from reading UI file 'handlecard.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLECARD_H
#define UI_HANDLECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "softkeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_HandleCard
{
public:
    QWidget *centralwidget;
    QLabel *label;
    SoftKeyBoard *widget;
    QPushButton *entryCardNumBt;
    QPushButton *prevBt;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *cardNum;
    QLabel *label_2;
    QLineEdit *carLe;
    QPushButton *readCardBt;

    void setupUi(QMainWindow *HandleCard)
    {
        if (HandleCard->objectName().isEmpty())
            HandleCard->setObjectName(QString::fromUtf8("HandleCard"));
        HandleCard->resize(800, 480);
        HandleCard->setMinimumSize(QSize(800, 480));
        HandleCard->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(HandleCard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 40, 161, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        widget = new SoftKeyBoard(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 240, 600, 230));
        widget->setMinimumSize(QSize(600, 230));
        widget->setMaximumSize(QSize(600, 230));
        entryCardNumBt = new QPushButton(centralwidget);
        entryCardNumBt->setObjectName(QString::fromUtf8("entryCardNumBt"));
        entryCardNumBt->setGeometry(QRect(290, 180, 111, 51));
        prevBt = new QPushButton(centralwidget);
        prevBt->setObjectName(QString::fromUtf8("prevBt"));
        prevBt->setGeometry(QRect(20, 20, 111, 51));
        prevBt->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/prev.jpg);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 120, 658, 57));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 35));
        label_3->setMaximumSize(QSize(80, 35));

        horizontalLayout->addWidget(label_3);

        cardNum = new QLabel(layoutWidget);
        cardNum->setObjectName(QString::fromUtf8("cardNum"));
        cardNum->setMinimumSize(QSize(239, 55));
        cardNum->setMaximumSize(QSize(239, 55));

        horizontalLayout->addWidget(cardNum);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 35));
        label_2->setMaximumSize(QSize(80, 35));

        horizontalLayout->addWidget(label_2);

        carLe = new QLineEdit(layoutWidget);
        carLe->setObjectName(QString::fromUtf8("carLe"));
        carLe->setMinimumSize(QSize(239, 55));
        carLe->setMaximumSize(QSize(239, 55));

        horizontalLayout->addWidget(carLe);

        readCardBt = new QPushButton(centralwidget);
        readCardBt->setObjectName(QString::fromUtf8("readCardBt"));
        readCardBt->setGeometry(QRect(50, 190, 121, 41));
        HandleCard->setCentralWidget(centralwidget);

        retranslateUi(HandleCard);

        QMetaObject::connectSlotsByName(HandleCard);
    } // setupUi

    void retranslateUi(QMainWindow *HandleCard)
    {
        HandleCard->setWindowTitle(QCoreApplication::translate("HandleCard", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("HandleCard", "\346\255\243\345\234\250\345\275\225\345\205\245\344\277\241\346\201\257", nullptr));
        entryCardNumBt->setText(QCoreApplication::translate("HandleCard", "\345\275\225\345\205\245", nullptr));
        prevBt->setText(QCoreApplication::translate("HandleCard", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("HandleCard", "\345\215\241\345\217\267:", nullptr));
        cardNum->setText(QCoreApplication::translate("HandleCard", "\350\257\267\347\202\271\345\207\273\350\257\273\345\215\241\351\224\256", nullptr));
        label_2->setText(QCoreApplication::translate("HandleCard", "\350\275\246\347\211\214\345\217\267:", nullptr));
        readCardBt->setText(QCoreApplication::translate("HandleCard", "\350\257\273\345\215\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandleCard: public Ui_HandleCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLECARD_H

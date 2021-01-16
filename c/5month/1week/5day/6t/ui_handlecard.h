/********************************************************************************
** Form generated from reading UI file 'handlecard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLECARD_H
#define UI_HANDLECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            HandleCard->setObjectName(QStringLiteral("HandleCard"));
        HandleCard->resize(800, 480);
        HandleCard->setMinimumSize(QSize(800, 480));
        HandleCard->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(HandleCard);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 40, 161, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        widget = new SoftKeyBoard(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 240, 600, 230));
        widget->setMinimumSize(QSize(600, 230));
        widget->setMaximumSize(QSize(600, 230));
        entryCardNumBt = new QPushButton(centralwidget);
        entryCardNumBt->setObjectName(QStringLiteral("entryCardNumBt"));
        entryCardNumBt->setGeometry(QRect(290, 180, 111, 51));
        prevBt = new QPushButton(centralwidget);
        prevBt->setObjectName(QStringLiteral("prevBt"));
        prevBt->setGeometry(QRect(20, 20, 111, 51));
        prevBt->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/prev.jpg);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 120, 658, 57));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 35));
        label_3->setMaximumSize(QSize(80, 35));

        horizontalLayout->addWidget(label_3);

        cardNum = new QLabel(layoutWidget);
        cardNum->setObjectName(QStringLiteral("cardNum"));
        cardNum->setMinimumSize(QSize(239, 55));
        cardNum->setMaximumSize(QSize(239, 55));

        horizontalLayout->addWidget(cardNum);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 35));
        label_2->setMaximumSize(QSize(80, 35));

        horizontalLayout->addWidget(label_2);

        carLe = new QLineEdit(layoutWidget);
        carLe->setObjectName(QStringLiteral("carLe"));
        carLe->setMinimumSize(QSize(239, 55));
        carLe->setMaximumSize(QSize(239, 55));

        horizontalLayout->addWidget(carLe);

        readCardBt = new QPushButton(centralwidget);
        readCardBt->setObjectName(QStringLiteral("readCardBt"));
        readCardBt->setGeometry(QRect(50, 190, 121, 41));
        HandleCard->setCentralWidget(centralwidget);

        retranslateUi(HandleCard);

        QMetaObject::connectSlotsByName(HandleCard);
    } // setupUi

    void retranslateUi(QMainWindow *HandleCard)
    {
        HandleCard->setWindowTitle(QApplication::translate("HandleCard", "MainWindow", 0));
        label->setText(QApplication::translate("HandleCard", "\346\255\243\345\234\250\345\275\225\345\205\245\344\277\241\346\201\257", 0));
        entryCardNumBt->setText(QApplication::translate("HandleCard", "\345\275\225\345\205\245", 0));
        prevBt->setText(QApplication::translate("HandleCard", "\350\277\224\345\233\236", 0));
        label_3->setText(QApplication::translate("HandleCard", "\345\215\241\345\217\267:", 0));
        cardNum->setText(QApplication::translate("HandleCard", "\350\257\267\347\202\271\345\207\273\350\257\273\345\215\241\351\224\256", 0));
        label_2->setText(QApplication::translate("HandleCard", "\350\275\246\347\211\214\345\217\267:", 0));
        readCardBt->setText(QApplication::translate("HandleCard", "\350\257\273\345\215\241", 0));
    } // retranslateUi

};

namespace Ui {
    class HandleCard: public Ui_HandleCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLECARD_H

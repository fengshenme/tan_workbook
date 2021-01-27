/********************************************************************************
** Form generated from reading UI file 'payrank.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYRANK_H
#define UI_PAYRANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "softkeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_PayRank
{
public:
    QWidget *centralwidget;
    SoftKeyBoard *widget;
    QPushButton *prevBt;
    QPushButton *delUse;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *cardNum;
    QPushButton *readCardBt;
    QLabel *label_5;
    QLineEdit *insigniaFindLe;
    QPushButton *insigniaFindBt;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *insigniaLba;
    QLineEdit *new_insignia_le;
    QPushButton *update_insigniaBt;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *oldPhoneLb;
    QLineEdit *new_phone_le;
    QPushButton *update_phoneBt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLabel *balance_lab;
    QLineEdit *money_count;
    QPushButton *rechargeBt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *pay_log_la;
    QLabel *label_3;
    QPushButton *reissue_cardBt;

    void setupUi(QMainWindow *PayRank)
    {
        if (PayRank->objectName().isEmpty())
            PayRank->setObjectName(QString::fromUtf8("PayRank"));
        PayRank->resize(800, 480);
        PayRank->setMinimumSize(QSize(800, 480));
        PayRank->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(PayRank);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new SoftKeyBoard(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 240, 600, 230));
        widget->setMinimumSize(QSize(600, 230));
        widget->setMaximumSize(QSize(600, 230));
        prevBt = new QPushButton(centralwidget);
        prevBt->setObjectName(QString::fromUtf8("prevBt"));
        prevBt->setGeometry(QRect(10, 390, 71, 81));
        prevBt->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/prev.jpg);"));
        delUse = new QPushButton(centralwidget);
        delUse->setObjectName(QString::fromUtf8("delUse"));
        delUse->setGeometry(QRect(10, 260, 89, 61));
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 0, 722, 231));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(72, 39));
        label->setMaximumSize(QSize(72, 39));

        horizontalLayout->addWidget(label);

        cardNum = new QLabel(widget1);
        cardNum->setObjectName(QString::fromUtf8("cardNum"));
        cardNum->setMinimumSize(QSize(200, 39));
        cardNum->setMaximumSize(QSize(200, 39));

        horizontalLayout->addWidget(cardNum);

        readCardBt = new QPushButton(widget1);
        readCardBt->setObjectName(QString::fromUtf8("readCardBt"));
        readCardBt->setMinimumSize(QSize(72, 39));
        readCardBt->setMaximumSize(QSize(72, 39));

        horizontalLayout->addWidget(readCardBt);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(72, 39));
        label_5->setMaximumSize(QSize(72, 39));

        horizontalLayout->addWidget(label_5);

        insigniaFindLe = new QLineEdit(widget1);
        insigniaFindLe->setObjectName(QString::fromUtf8("insigniaFindLe"));
        insigniaFindLe->setMinimumSize(QSize(200, 39));
        insigniaFindLe->setMaximumSize(QSize(200, 39));

        horizontalLayout->addWidget(insigniaFindLe);

        insigniaFindBt = new QPushButton(widget1);
        insigniaFindBt->setObjectName(QString::fromUtf8("insigniaFindBt"));
        insigniaFindBt->setMinimumSize(QSize(72, 39));
        insigniaFindBt->setMaximumSize(QSize(72, 39));

        horizontalLayout->addWidget(insigniaFindBt);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(90, 39));
        label_2->setMaximumSize(QSize(90, 39));

        horizontalLayout_2->addWidget(label_2);

        insigniaLba = new QLabel(widget1);
        insigniaLba->setObjectName(QString::fromUtf8("insigniaLba"));
        insigniaLba->setMinimumSize(QSize(220, 39));
        insigniaLba->setMaximumSize(QSize(220, 39));

        horizontalLayout_2->addWidget(insigniaLba);

        new_insignia_le = new QLineEdit(widget1);
        new_insignia_le->setObjectName(QString::fromUtf8("new_insignia_le"));
        new_insignia_le->setMinimumSize(QSize(220, 39));
        new_insignia_le->setMaximumSize(QSize(220, 39));

        horizontalLayout_2->addWidget(new_insignia_le);

        update_insigniaBt = new QPushButton(widget1);
        update_insigniaBt->setObjectName(QString::fromUtf8("update_insigniaBt"));
        update_insigniaBt->setMinimumSize(QSize(150, 39));
        update_insigniaBt->setMaximumSize(QSize(150, 39));

        horizontalLayout_2->addWidget(update_insigniaBt);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(90, 39));
        label_6->setMaximumSize(QSize(90, 39));

        horizontalLayout_3->addWidget(label_6);

        oldPhoneLb = new QLabel(widget1);
        oldPhoneLb->setObjectName(QString::fromUtf8("oldPhoneLb"));
        oldPhoneLb->setMinimumSize(QSize(220, 39));
        oldPhoneLb->setMaximumSize(QSize(220, 39));

        horizontalLayout_3->addWidget(oldPhoneLb);

        new_phone_le = new QLineEdit(widget1);
        new_phone_le->setObjectName(QString::fromUtf8("new_phone_le"));
        new_phone_le->setMinimumSize(QSize(220, 39));
        new_phone_le->setMaximumSize(QSize(220, 39));

        horizontalLayout_3->addWidget(new_phone_le);

        update_phoneBt = new QPushButton(widget1);
        update_phoneBt->setObjectName(QString::fromUtf8("update_phoneBt"));
        update_phoneBt->setMinimumSize(QSize(150, 39));
        update_phoneBt->setMaximumSize(QSize(150, 39));

        horizontalLayout_3->addWidget(update_phoneBt);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(90, 39));
        label_8->setMaximumSize(QSize(90, 39));

        horizontalLayout_4->addWidget(label_8);

        balance_lab = new QLabel(widget1);
        balance_lab->setObjectName(QString::fromUtf8("balance_lab"));
        balance_lab->setMinimumSize(QSize(220, 39));
        balance_lab->setMaximumSize(QSize(220, 39));

        horizontalLayout_4->addWidget(balance_lab);

        money_count = new QLineEdit(widget1);
        money_count->setObjectName(QString::fromUtf8("money_count"));
        money_count->setMinimumSize(QSize(220, 39));
        money_count->setMaximumSize(QSize(220, 39));

        horizontalLayout_4->addWidget(money_count);

        rechargeBt = new QPushButton(widget1);
        rechargeBt->setObjectName(QString::fromUtf8("rechargeBt"));
        rechargeBt->setMinimumSize(QSize(150, 39));
        rechargeBt->setMaximumSize(QSize(150, 39));

        horizontalLayout_4->addWidget(rechargeBt);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_11 = new QLabel(widget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(90, 39));
        label_11->setMaximumSize(QSize(90, 39));

        horizontalLayout_5->addWidget(label_11);

        pay_log_la = new QLabel(widget1);
        pay_log_la->setObjectName(QString::fromUtf8("pay_log_la"));
        pay_log_la->setMinimumSize(QSize(350, 39));
        pay_log_la->setMaximumSize(QSize(350, 39));

        horizontalLayout_5->addWidget(pay_log_la);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(191, 39));
        label_3->setMaximumSize(QSize(191, 39));

        horizontalLayout_5->addWidget(label_3);

        reissue_cardBt = new QPushButton(widget1);
        reissue_cardBt->setObjectName(QString::fromUtf8("reissue_cardBt"));
        reissue_cardBt->setMinimumSize(QSize(65, 39));
        reissue_cardBt->setMaximumSize(QSize(60, 39));

        horizontalLayout_5->addWidget(reissue_cardBt);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        PayRank->setCentralWidget(centralwidget);

        retranslateUi(PayRank);

        QMetaObject::connectSlotsByName(PayRank);
    } // setupUi

    void retranslateUi(QMainWindow *PayRank)
    {
        PayRank->setWindowTitle(QCoreApplication::translate("PayRank", "MainWindow", nullptr));
        prevBt->setText(QCoreApplication::translate("PayRank", "\350\277\224\345\233\236", nullptr));
        delUse->setText(QCoreApplication::translate("PayRank", "\345\210\240\351\231\244\350\257\245\347\224\250\346\210\267", nullptr));
        label->setText(QCoreApplication::translate("PayRank", "\345\205\205\345\200\274\345\215\241\345\217\267:", nullptr));
        cardNum->setText(QCoreApplication::translate("PayRank", "\345\215\241\344\270\242\344\272\206\344\270\215\347\224\250\347\202\271\345\207\273\350\257\273\345\215\241", nullptr));
        readCardBt->setText(QCoreApplication::translate("PayRank", "\350\257\273\345\215\241", nullptr));
        label_5->setText(QCoreApplication::translate("PayRank", "\350\275\246\347\211\214\345\217\267:", nullptr));
        insigniaFindLe->setPlaceholderText(QCoreApplication::translate("PayRank", "\350\276\223\345\205\245\350\275\246\347\211\214\345\217\267", nullptr));
        insigniaFindBt->setText(QCoreApplication::translate("PayRank", "\346\237\245\346\211\276", nullptr));
        label_2->setText(QCoreApplication::translate("PayRank", "\350\275\246\347\211\214\345\217\267:", nullptr));
        insigniaLba->setText(QCoreApplication::translate("PayRank", "\347\216\260\345\234\250\350\275\246\347\211\214\345\217\267", nullptr));
        new_insignia_le->setPlaceholderText(QCoreApplication::translate("PayRank", "\350\257\267\350\276\223\345\205\245\346\226\260\350\275\246\347\211\214\345\217\267", nullptr));
        update_insigniaBt->setText(QCoreApplication::translate("PayRank", "\344\277\256\346\224\271\350\275\246\347\211\214\345\217\267", nullptr));
        label_6->setText(QCoreApplication::translate("PayRank", "\346\211\213\346\234\272\345\217\267:", nullptr));
        oldPhoneLb->setText(QCoreApplication::translate("PayRank", "\346\227\240", nullptr));
        new_phone_le->setPlaceholderText(QCoreApplication::translate("PayRank", "\350\257\267\350\276\223\345\205\245\346\226\260\346\211\213\346\234\272\345\217\267", nullptr));
        update_phoneBt->setText(QCoreApplication::translate("PayRank", "\344\277\256\346\224\271\346\211\213\346\234\272\345\217\267", nullptr));
        label_8->setText(QCoreApplication::translate("PayRank", "\344\275\231\351\242\235:", nullptr));
        balance_lab->setText(QCoreApplication::translate("PayRank", "\346\227\240", nullptr));
        money_count->setPlaceholderText(QCoreApplication::translate("PayRank", "\350\257\267\350\276\223\345\205\245\345\205\205\345\200\274\351\207\221\351\242\235", nullptr));
        rechargeBt->setText(QCoreApplication::translate("PayRank", "\345\205\205\345\200\274", nullptr));
        label_11->setText(QCoreApplication::translate("PayRank", "\345\205\205\345\200\274\350\256\260\345\275\225:", nullptr));
        pay_log_la->setText(QCoreApplication::translate("PayRank", "\346\227\240", nullptr));
        label_3->setText(QCoreApplication::translate("PayRank", "\350\241\245\345\215\241\345\211\215\350\257\267\350\257\273\345\205\245\346\226\260\345\215\241\344\270\215:", nullptr));
        reissue_cardBt->setText(QCoreApplication::translate("PayRank", "\350\241\245\345\215\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PayRank: public Ui_PayRank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYRANK_H

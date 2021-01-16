/********************************************************************************
** Form generated from reading UI file 'repasswin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPASSWIN_H
#define UI_REPASSWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RePassWin
{
public:
    QPushButton *repass;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passw;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *enanle;

    void setupUi(QWidget *RePassWin)
    {
        if (RePassWin->objectName().isEmpty())
            RePassWin->setObjectName(QString::fromUtf8("RePassWin"));
        RePassWin->resize(380, 430);
        RePassWin->setMinimumSize(QSize(380, 430));
        RePassWin->setMaximumSize(QSize(380, 430));
        repass = new QPushButton(RePassWin);
        repass->setObjectName(QString::fromUtf8("repass"));
        repass->setGeometry(QRect(110, 350, 121, 41));
        widget = new QWidget(RePassWin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 50, 351, 291));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 39));
        label->setMaximumSize(QSize(80, 39));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        username = new QLineEdit(widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setMinimumSize(QSize(260, 39));
        username->setMaximumSize(QSize(260, 39));

        horizontalLayout->addWidget(username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 39));
        label_2->setMaximumSize(QSize(80, 39));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        passw = new QLineEdit(widget);
        passw->setObjectName(QString::fromUtf8("passw"));
        passw->setMinimumSize(QSize(260, 39));
        passw->setMaximumSize(QSize(260, 39));
        passw->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passw);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 39));
        label_3->setMaximumSize(QSize(80, 39));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(260, 39));
        comboBox->setMaximumSize(QSize(260, 39));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 39));
        label_4->setMaximumSize(QSize(80, 39));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        enanle = new QLineEdit(widget);
        enanle->setObjectName(QString::fromUtf8("enanle"));
        enanle->setMinimumSize(QSize(260, 39));
        enanle->setMaximumSize(QSize(260, 39));

        horizontalLayout_4->addWidget(enanle);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(RePassWin);

        QMetaObject::connectSlotsByName(RePassWin);
    } // setupUi

    void retranslateUi(QWidget *RePassWin)
    {
        RePassWin->setWindowTitle(QApplication::translate("RePassWin", "Form", nullptr));
        repass->setText(QApplication::translate("RePassWin", "\351\207\215\347\275\256", nullptr));
        label->setText(QApplication::translate("RePassWin", "\347\224\250\346\210\267\345\220\215:", nullptr));
        username->setPlaceholderText(QApplication::translate("RePassWin", "\350\246\201\346\211\276\345\233\236\345\257\206\347\240\201\347\232\204\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("RePassWin", "\346\226\260\345\257\206\347\240\201:", nullptr));
        passw->setPlaceholderText(QApplication::translate("RePassWin", "\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("RePassWin", "\345\257\206\344\277\235\351\227\256\351\242\230:", nullptr));
        label_4->setText(QApplication::translate("RePassWin", "\351\227\256\351\242\230\347\255\224\346\241\210:", nullptr));
        enanle->setPlaceholderText(QApplication::translate("RePassWin", "\350\276\223\345\205\245\346\263\250\345\206\214\346\227\266\347\225\231\344\270\213\347\232\204\345\257\206\344\277\235\351\227\256\351\242\230\347\255\224\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RePassWin: public Ui_RePassWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPASSWIN_H

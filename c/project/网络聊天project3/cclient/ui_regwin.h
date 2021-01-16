/********************************************************************************
** Form generated from reading UI file 'regwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWIN_H
#define UI_REGWIN_H

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

class Ui_RegWin
{
public:
    QPushButton *registerbt;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *enanle;

    void setupUi(QWidget *RegWin)
    {
        if (RegWin->objectName().isEmpty())
            RegWin->setObjectName(QString::fromUtf8("RegWin"));
        RegWin->resize(380, 430);
        RegWin->setMinimumSize(QSize(380, 430));
        RegWin->setMaximumSize(QSize(380, 430));
        registerbt = new QPushButton(RegWin);
        registerbt->setObjectName(QString::fromUtf8("registerbt"));
        registerbt->setGeometry(QRect(120, 320, 100, 50));
        registerbt->setMinimumSize(QSize(100, 50));
        registerbt->setMaximumSize(QSize(100, 50));
        registerbt->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        widget = new QWidget(RegWin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 70, 351, 231));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 39));
        label_2->setMaximumSize(QSize(80, 39));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        username = new QLineEdit(widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setMinimumSize(QSize(260, 39));
        username->setMaximumSize(QSize(260, 39));

        horizontalLayout->addWidget(username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 39));
        label_3->setMaximumSize(QSize(80, 39));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        password = new QLineEdit(widget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(260, 39));
        password->setMaximumSize(QSize(260, 39));
        password->setMaxLength(16);

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 39));
        label_4->setMaximumSize(QSize(80, 39));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(260, 39));
        comboBox->setMaximumSize(QSize(260, 39));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 39));
        label->setMaximumSize(QSize(80, 39));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);

        enanle = new QLineEdit(widget);
        enanle->setObjectName(QString::fromUtf8("enanle"));
        enanle->setMinimumSize(QSize(260, 39));
        enanle->setMaximumSize(QSize(260, 39));

        horizontalLayout_4->addWidget(enanle);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(RegWin);

        QMetaObject::connectSlotsByName(RegWin);
    } // setupUi

    void retranslateUi(QWidget *RegWin)
    {
        RegWin->setWindowTitle(QApplication::translate("RegWin", "Form", nullptr));
        registerbt->setText(QApplication::translate("RegWin", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QApplication::translate("RegWin", "\347\224\250\346\210\267\345\220\215:", nullptr));
        username->setPlaceholderText(QApplication::translate("RegWin", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\346\230\265\347\247\260", nullptr));
        label_3->setText(QApplication::translate("RegWin", "\345\257\206\347\240\201:", nullptr));
        password->setPlaceholderText(QApplication::translate("RegWin", "\350\276\223\345\205\245\345\257\206\347\240\201\351\225\277\345\272\246\344\270\215\350\203\275\350\266\205\350\277\20716\344\275\215", nullptr));
        label_4->setText(QApplication::translate("RegWin", "\345\257\206\344\277\235\351\227\256\351\242\230:", nullptr));
        label->setText(QApplication::translate("RegWin", "\351\227\256\351\242\230\347\255\224\346\241\210:", nullptr));
        enanle->setPlaceholderText(QApplication::translate("RegWin", "\350\257\267\350\276\223\345\205\245\347\255\224\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegWin: public Ui_RegWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWIN_H

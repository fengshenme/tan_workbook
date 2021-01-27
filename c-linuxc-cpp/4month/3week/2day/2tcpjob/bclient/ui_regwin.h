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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegWin
{
public:
    QLineEdit *username;
    QLabel *label;
    QPushButton *registerbt;
    QLineEdit *password;
    QLineEdit *enanle;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;

    void setupUi(QWidget *RegWin)
    {
        if (RegWin->objectName().isEmpty())
            RegWin->setObjectName(QString::fromUtf8("RegWin"));
        RegWin->resize(360, 408);
        username = new QLineEdit(RegWin);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(110, 95, 200, 39));
        username->setMinimumSize(QSize(200, 39));
        username->setMaximumSize(QSize(200, 39));
        label = new QLabel(RegWin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 260, 101, 16));
        registerbt = new QPushButton(RegWin);
        registerbt->setObjectName(QString::fromUtf8("registerbt"));
        registerbt->setGeometry(QRect(130, 310, 100, 50));
        registerbt->setMinimumSize(QSize(100, 50));
        registerbt->setMaximumSize(QSize(100, 50));
        registerbt->setStyleSheet(QString::fromUtf8("border-radius:25px; \n"
"background-color: rgb(255, 255, 255);"));
        password = new QLineEdit(RegWin);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(110, 145, 200, 39));
        password->setMinimumSize(QSize(200, 39));
        password->setMaximumSize(QSize(200, 39));
        password->setMaxLength(16);
        enanle = new QLineEdit(RegWin);
        enanle->setObjectName(QString::fromUtf8("enanle"));
        enanle->setGeometry(QRect(110, 245, 200, 39));
        enanle->setMinimumSize(QSize(200, 39));
        enanle->setMaximumSize(QSize(200, 39));
        label_2 = new QLabel(RegWin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 72, 15));
        label_3 = new QLabel(RegWin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 150, 72, 15));
        comboBox = new QComboBox(RegWin);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 195, 200, 39));
        comboBox->setMinimumSize(QSize(200, 39));
        comboBox->setMaximumSize(QSize(200, 39));
        label_4 = new QLabel(RegWin);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1, 210, 101, 20));

        retranslateUi(RegWin);

        QMetaObject::connectSlotsByName(RegWin);
    } // setupUi

    void retranslateUi(QWidget *RegWin)
    {
        RegWin->setWindowTitle(QApplication::translate("RegWin", "Form", nullptr));
        username->setPlaceholderText(QApplication::translate("RegWin", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\346\230\265\347\247\260", nullptr));
        label->setText(QApplication::translate("RegWin", "\345\257\206\344\277\235\351\227\256\351\242\230\347\255\224\346\241\210:", nullptr));
        registerbt->setText(QApplication::translate("RegWin", "\346\263\250\345\206\214", nullptr));
        password->setPlaceholderText(QApplication::translate("RegWin", "\350\276\223\345\205\245\345\257\206\347\240\201\351\225\277\345\272\246\344\270\215\350\203\275\350\266\205\350\277\20716\344\275\215", nullptr));
        enanle->setPlaceholderText(QApplication::translate("RegWin", "\350\257\267\350\276\223\345\205\245\347\255\224\346\241\210", nullptr));
        label_2->setText(QApplication::translate("RegWin", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_3->setText(QApplication::translate("RegWin", "\345\257\206\347\240\201:", nullptr));
        label_4->setText(QApplication::translate("RegWin", "\351\200\211\346\213\251\345\257\206\344\277\235\351\227\256\351\242\230:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegWin: public Ui_RegWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWIN_H

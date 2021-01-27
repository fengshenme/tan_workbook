/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QWidget *centralwidget;
    QPushButton *handle_card_bt;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *prev_win;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(800, 480);
        Admin->setMinimumSize(QSize(800, 480));
        Admin->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        handle_card_bt = new QPushButton(centralwidget);
        handle_card_bt->setObjectName(QString::fromUtf8("handle_card_bt"));
        handle_card_bt->setGeometry(QRect(80, 100, 161, 321));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 100, 161, 321));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(560, 100, 161, 321));
        prev_win = new QPushButton(centralwidget);
        prev_win->setObjectName(QString::fromUtf8("prev_win"));
        prev_win->setGeometry(QRect(20, 20, 50, 50));
        prev_win->setMinimumSize(QSize(50, 50));
        prev_win->setMaximumSize(QSize(50, 50));
        prev_win->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/prev.jpg);"));
        Admin->setCentralWidget(centralwidget);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "MainWindow", nullptr));
        handle_card_bt->setText(QCoreApplication::translate("Admin", "\345\275\225\345\205\245\350\275\246\344\270\273\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Admin", "\346\233\264\346\226\260\350\275\246\344\270\273\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Admin", "\346\237\245\347\234\213\350\275\246\350\276\206\347\205\247\347\211\207", nullptr));
        prev_win->setText(QCoreApplication::translate("Admin", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H

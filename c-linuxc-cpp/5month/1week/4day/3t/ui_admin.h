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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QWidget *centralwidget;
    QPushButton *prev_win;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *handle_card_bt;
    QPushButton *updateUse;
    QPushButton *findAllBt;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(800, 480);
        Admin->setMinimumSize(QSize(800, 480));
        Admin->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        prev_win = new QPushButton(centralwidget);
        prev_win->setObjectName(QString::fromUtf8("prev_win"));
        prev_win->setGeometry(QRect(20, 20, 50, 50));
        prev_win->setMinimumSize(QSize(50, 50));
        prev_win->setMaximumSize(QSize(50, 50));
        prev_win->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/prev.jpg);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 70, 691, 381));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        handle_card_bt = new QPushButton(widget);
        handle_card_bt->setObjectName(QString::fromUtf8("handle_card_bt"));
        handle_card_bt->setMinimumSize(QSize(161, 321));
        handle_card_bt->setMaximumSize(QSize(161, 321));

        horizontalLayout->addWidget(handle_card_bt);

        updateUse = new QPushButton(widget);
        updateUse->setObjectName(QString::fromUtf8("updateUse"));
        updateUse->setMinimumSize(QSize(161, 321));
        updateUse->setMaximumSize(QSize(161, 321));

        horizontalLayout->addWidget(updateUse);

        findAllBt = new QPushButton(widget);
        findAllBt->setObjectName(QString::fromUtf8("findAllBt"));
        findAllBt->setMinimumSize(QSize(161, 321));
        findAllBt->setMaximumSize(QSize(161, 321));

        horizontalLayout->addWidget(findAllBt);

        Admin->setCentralWidget(centralwidget);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "MainWindow", nullptr));
        prev_win->setText(QCoreApplication::translate("Admin", "\350\277\224\345\233\236", nullptr));
        handle_card_bt->setText(QCoreApplication::translate("Admin", "\345\275\225\345\205\245\350\275\246\344\270\273\344\277\241\346\201\257", nullptr));
        updateUse->setText(QCoreApplication::translate("Admin", "\346\233\264\346\226\260\350\275\246\344\270\273\344\277\241\346\201\257", nullptr));
        findAllBt->setText(QCoreApplication::translate("Admin", "\346\237\245\347\234\213\346\211\200\346\234\211\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H

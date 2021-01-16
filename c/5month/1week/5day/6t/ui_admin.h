/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            Admin->setObjectName(QStringLiteral("Admin"));
        Admin->resize(800, 480);
        Admin->setMinimumSize(QSize(800, 480));
        Admin->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        prev_win = new QPushButton(centralwidget);
        prev_win->setObjectName(QStringLiteral("prev_win"));
        prev_win->setGeometry(QRect(20, 20, 50, 50));
        prev_win->setMinimumSize(QSize(50, 50));
        prev_win->setMaximumSize(QSize(50, 50));
        prev_win->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/prev.jpg);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 70, 691, 381));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        handle_card_bt = new QPushButton(widget);
        handle_card_bt->setObjectName(QStringLiteral("handle_card_bt"));
        handle_card_bt->setMinimumSize(QSize(161, 321));
        handle_card_bt->setMaximumSize(QSize(161, 321));

        horizontalLayout->addWidget(handle_card_bt);

        updateUse = new QPushButton(widget);
        updateUse->setObjectName(QStringLiteral("updateUse"));
        updateUse->setMinimumSize(QSize(161, 321));
        updateUse->setMaximumSize(QSize(161, 321));

        horizontalLayout->addWidget(updateUse);

        findAllBt = new QPushButton(widget);
        findAllBt->setObjectName(QStringLiteral("findAllBt"));
        findAllBt->setMinimumSize(QSize(161, 321));
        findAllBt->setMaximumSize(QSize(161, 321));

        horizontalLayout->addWidget(findAllBt);

        Admin->setCentralWidget(centralwidget);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "MainWindow", 0));
        prev_win->setText(QApplication::translate("Admin", "\350\277\224\345\233\236", 0));
        handle_card_bt->setText(QApplication::translate("Admin", "\345\275\225\345\205\245\350\275\246\344\270\273\344\277\241\346\201\257", 0));
        updateUse->setText(QApplication::translate("Admin", "\346\233\264\346\226\260\350\275\246\344\270\273\344\277\241\346\201\257", 0));
        findAllBt->setText(QApplication::translate("Admin", "\346\237\245\347\234\213\346\211\200\346\234\211\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H

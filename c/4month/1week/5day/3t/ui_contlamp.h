/********************************************************************************
** Form generated from reading UI file 'contlamp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTLAMP_H
#define UI_CONTLAMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContLamp
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ContLamp)
    {
        if (ContLamp->objectName().isEmpty())
            ContLamp->setObjectName(QStringLiteral("ContLamp"));
        ContLamp->resize(800, 600);
        centralwidget = new QWidget(ContLamp);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(250, 80, 256, 192));
        ContLamp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ContLamp);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ContLamp->setMenuBar(menubar);
        statusbar = new QStatusBar(ContLamp);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ContLamp->setStatusBar(statusbar);

        retranslateUi(ContLamp);

        QMetaObject::connectSlotsByName(ContLamp);
    } // setupUi

    void retranslateUi(QMainWindow *ContLamp)
    {
        ContLamp->setWindowTitle(QApplication::translate("ContLamp", "MainWindow", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("ContLamp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\350\277\231\346\230\257\344\270\200\344\270\252\347\201\257</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContLamp: public Ui_ContLamp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTLAMP_H

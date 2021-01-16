/********************************************************************************
** Form generated from reading UI file 'airca.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRCA_H
#define UI_AIRCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Airca
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Airca)
    {
        if (Airca->objectName().isEmpty())
            Airca->setObjectName(QStringLiteral("Airca"));
        Airca->resize(800, 600);
        centralwidget = new QWidget(Airca);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(260, 160, 256, 192));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 70, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 60, 181, 41));
        Airca->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Airca);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Airca->setMenuBar(menubar);
        statusbar = new QStatusBar(Airca);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Airca->setStatusBar(statusbar);

        retranslateUi(Airca);

        QMetaObject::connectSlotsByName(Airca);
    } // setupUi

    void retranslateUi(QMainWindow *Airca)
    {
        Airca->setWindowTitle(QApplication::translate("Airca", "MainWindow", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Airca", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\350\277\231\346\230\257\344\270\200\344\270\252\347\251\272\350\260\203</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Airca", "\350\277\224\345\233\236", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Airca", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Airca: public Ui_Airca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRCA_H

/********************************************************************************
** Form generated from reading UI file 'airwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRWIN_H
#define UI_AIRWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AirWin
{
public:
    QWidget *centralwidget;
    QPushButton *retpb;
    QSpinBox *spinBox;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AirWin)
    {
        if (AirWin->objectName().isEmpty())
            AirWin->setObjectName(QStringLiteral("AirWin"));
        AirWin->resize(800, 600);
        QFont font;
        font.setPointSize(12);
        AirWin->setFont(font);
        centralwidget = new QWidget(AirWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        retpb = new QPushButton(centralwidget);
        retpb->setObjectName(QStringLiteral("retpb"));
        retpb->setGeometry(QRect(590, 60, 93, 40));
        retpb->setStyleSheet(QLatin1String("border-radius:20px; \n"
"background-color: rgb(255, 255, 255);"));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(360, 350, 81, 31));
        spinBox->setMaximum(999);
        spinBox->setValue(26);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(260, 60, 141, 51));
        lcdNumber->setFont(font);
        lcdNumber->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"\n"
""));
        lcdNumber->setProperty("value", QVariant(26));
        lcdNumber->setProperty("intValue", QVariant(26));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 350, 101, 31));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        AirWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AirWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        AirWin->setMenuBar(menubar);
        statusbar = new QStatusBar(AirWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AirWin->setStatusBar(statusbar);

        retranslateUi(AirWin);

        QMetaObject::connectSlotsByName(AirWin);
    } // setupUi

    void retranslateUi(QMainWindow *AirWin)
    {
        AirWin->setWindowTitle(QApplication::translate("AirWin", "MainWindow", Q_NULLPTR));
        retpb->setText(QApplication::translate("AirWin", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("AirWin", "\347\251\272\350\260\203\350\256\276\347\275\256\346\270\251\345\272\246:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AirWin: public Ui_AirWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRWIN_H

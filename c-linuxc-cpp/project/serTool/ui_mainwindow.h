/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label;
    QLabel *label_2;
    QComboBox *portcbox;
    QLabel *label_3;
    QComboBox *portcbox_2;
    QLabel *label_5;
    QLabel *label_4;
    QComboBox *portcbox_3;
    QComboBox *portcbox_4;
    QComboBox *portcbox_5;
    QListWidget *read_listWidget;
    QTextEdit *send_textEdit;
    QLCDNumber *lcdNumber;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *close_button;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clear_button;
    QPushButton *send_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 270, 122, 167));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(71, 21));
        label_6->setMaximumSize(QSize(71, 21));

        verticalLayout->addWidget(label_6);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(32, 24, 81, 31));
        label->setMinimumSize(QSize(81, 31));
        label->setMaximumSize(QSize(81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(32, 73, 81, 31));
        label_2->setMinimumSize(QSize(81, 31));
        label_2->setMaximumSize(QSize(81, 31));
        portcbox = new QComboBox(centralwidget);
        portcbox->setObjectName(QString::fromUtf8("portcbox"));
        portcbox->setGeometry(QRect(130, 24, 220, 31));
        portcbox->setMinimumSize(QSize(220, 31));
        portcbox->setMaximumSize(QSize(220, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(32, 122, 81, 31));
        label_3->setMinimumSize(QSize(81, 31));
        label_3->setMaximumSize(QSize(81, 31));
        portcbox_2 = new QComboBox(centralwidget);
        portcbox_2->setObjectName(QString::fromUtf8("portcbox_2"));
        portcbox_2->setGeometry(QRect(130, 73, 220, 31));
        portcbox_2->setMinimumSize(QSize(220, 31));
        portcbox_2->setMaximumSize(QSize(220, 31));
        portcbox_2->setEditable(false);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(32, 220, 81, 31));
        label_5->setMinimumSize(QSize(81, 31));
        label_5->setMaximumSize(QSize(81, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(32, 171, 81, 31));
        label_4->setMinimumSize(QSize(81, 31));
        label_4->setMaximumSize(QSize(81, 31));
        portcbox_3 = new QComboBox(centralwidget);
        portcbox_3->setObjectName(QString::fromUtf8("portcbox_3"));
        portcbox_3->setGeometry(QRect(130, 122, 220, 31));
        portcbox_3->setMinimumSize(QSize(220, 31));
        portcbox_3->setMaximumSize(QSize(220, 31));
        portcbox_4 = new QComboBox(centralwidget);
        portcbox_4->setObjectName(QString::fromUtf8("portcbox_4"));
        portcbox_4->setGeometry(QRect(130, 171, 220, 31));
        portcbox_4->setMinimumSize(QSize(220, 31));
        portcbox_4->setMaximumSize(QSize(220, 31));
        portcbox_5 = new QComboBox(centralwidget);
        portcbox_5->setObjectName(QString::fromUtf8("portcbox_5"));
        portcbox_5->setGeometry(QRect(130, 220, 220, 31));
        portcbox_5->setMinimumSize(QSize(220, 31));
        portcbox_5->setMaximumSize(QSize(220, 31));
        read_listWidget = new QListWidget(centralwidget);
        read_listWidget->setObjectName(QString::fromUtf8("read_listWidget"));
        read_listWidget->setGeometry(QRect(390, 20, 360, 251));
        read_listWidget->setMinimumSize(QSize(360, 251));
        read_listWidget->setMaximumSize(QSize(360, 251));
        send_textEdit = new QTextEdit(centralwidget);
        send_textEdit->setObjectName(QString::fromUtf8("send_textEdit"));
        send_textEdit->setGeometry(QRect(390, 290, 360, 250));
        send_textEdit->setMinimumSize(QSize(360, 250));
        send_textEdit->setMaximumSize(QSize(360, 250));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 470, 361, 71));
        lcdNumber->setDigitCount(20);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 280, 197, 115));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(93, 51));
        pushButton->setMaximumSize(QSize(93, 51));

        horizontalLayout->addWidget(pushButton);

        close_button = new QPushButton(widget);
        close_button->setObjectName(QString::fromUtf8("close_button"));
        sizePolicy.setHeightForWidth(close_button->sizePolicy().hasHeightForWidth());
        close_button->setSizePolicy(sizePolicy);
        close_button->setMinimumSize(QSize(93, 51));
        close_button->setMaximumSize(QSize(93, 51));

        horizontalLayout->addWidget(close_button);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        clear_button = new QPushButton(widget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        sizePolicy.setHeightForWidth(clear_button->sizePolicy().hasHeightForWidth());
        clear_button->setSizePolicy(sizePolicy);
        clear_button->setMinimumSize(QSize(93, 51));
        clear_button->setMaximumSize(QSize(93, 51));

        horizontalLayout_2->addWidget(clear_button);

        send_button = new QPushButton(widget);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        sizePolicy.setHeightForWidth(send_button->sizePolicy().hasHeightForWidth());
        send_button->setSizePolicy(sizePolicy);
        send_button->setMinimumSize(QSize(93, 51));
        send_button->setMaximumSize(QSize(93, 51));

        horizontalLayout_2->addWidget(send_button);


        verticalLayout_2->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247:", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "XON/XOFF", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "RTS/CTS", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "\346\227\240", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214:", nullptr));
        send_textEdit->setPlaceholderText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257\350\276\223\345\205\245\346\241\206", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        close_button->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        clear_button->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\276\223\345\207\272", nullptr));
        send_button->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

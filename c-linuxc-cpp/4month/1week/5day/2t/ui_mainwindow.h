/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_13;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_14;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_16;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(752, 646);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(120, 50));
        textBrowser->setMaximumSize(QSize(12336, 50));

        horizontalLayout->addWidget(textBrowser);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(75, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(75, 75));
        pushButton->setMaximumSize(QSize(75, 75));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(75, 75));
        pushButton_2->setMaximumSize(QSize(75, 75));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(75, 75));
        pushButton_3->setMaximumSize(QSize(75, 75));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(75, 75));
        pushButton_13->setMaximumSize(QSize(75, 75));

        horizontalLayout_2->addWidget(pushButton_13);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(75, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(75, 75));
        pushButton_17->setMaximumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(75, 75));
        pushButton_18->setMaximumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(pushButton_18);

        pushButton_19 = new QPushButton(centralWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(75, 75));
        pushButton_19->setMaximumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(pushButton_19);

        pushButton_20 = new QPushButton(centralWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setMinimumSize(QSize(75, 75));
        pushButton_20->setMaximumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(pushButton_20);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(75, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(75, 75));
        pushButton_4->setMaximumSize(QSize(75, 75));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(75, 75));
        pushButton_6->setMaximumSize(QSize(75, 75));

        horizontalLayout_4->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(75, 75));
        pushButton_5->setMaximumSize(QSize(75, 75));

        horizontalLayout_4->addWidget(pushButton_5);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(75, 75));
        pushButton_14->setMaximumSize(QSize(75, 75));

        horizontalLayout_4->addWidget(pushButton_14);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_5 = new QSpacerItem(75, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(75, 75));
        pushButton_10->setMaximumSize(QSize(75, 75));

        horizontalLayout_5->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(75, 75));
        pushButton_11->setMaximumSize(QSize(75, 75));

        horizontalLayout_5->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(75, 75));
        pushButton_12->setMaximumSize(QSize(75, 75));

        horizontalLayout_5->addWidget(pushButton_12);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(75, 75));
        pushButton_16->setMaximumSize(QSize(75, 75));

        horizontalLayout_5->addWidget(pushButton_16);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 752, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton_20->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "*", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "C", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "=", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "/", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

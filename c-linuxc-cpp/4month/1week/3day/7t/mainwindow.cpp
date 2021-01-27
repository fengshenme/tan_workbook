#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLineEdit *le1 = new QLineEdit(this);
    QLineEdit *le2 = new QLineEdit(this);
    le1->setGeometry(20, 20, 200, 30);
    le2->setGeometry(20, 70, 200, 30);

//        const std::string s1 = std::string("请输入账号");
        le1->setPlaceholderText(QString("请输入账号"));
//    le1->setPlaceholderText("pls input num");
    le2->setPlaceholderText(QString("请输入密码"));
    //    le2->setPlaceholderText(QString::fromLocal8Bit("输入的中文"));

    le2->setMaxLength(10);
    le2->setEchoMode(le2->Password);



}

MainWindow::~MainWindow()
{
    delete ui;
}

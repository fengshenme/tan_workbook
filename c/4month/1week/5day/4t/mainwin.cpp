#include "mainwin.h"
#include "ui_mainwin.h"
#include <QDebug>
mainwin::mainwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwin)
{
    ui->setupUi(this);
}

mainwin::~mainwin()
{
    delete ui;
}
//返回按钮
void mainwin::on_retbt_clicked()
{
    //得到上一级窗口，并显示
    this->parentWidget()->show();
    //当前主窗口关闭
    delete this;
}
 //自定义一个槽函数，接收登录界面通过信号发送过来的参数
void mainwin::fun(QString str1, QString str2)
{
    qDebug()<<"str1 str2分别是: "<<str1<<"   "<<str2;
    ui->label_2->setText(str1);
    ui->label_3->setText(str2);
}

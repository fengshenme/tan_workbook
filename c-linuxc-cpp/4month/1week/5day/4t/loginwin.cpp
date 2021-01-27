#include "loginwin.h"
#include "ui_loginwin.h"
#include "mainwin.h"
loginwin::loginwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginwin)
{
    ui->setupUi(this);
}

loginwin::~loginwin()
{
    delete ui;
}
//登录按钮
void loginwin::on_loginbt_clicked()
{
    //获取用户名和密码
    QString name=ui->usrle->text();
    QString passwd=ui->passwdle->text();
    if(name=="gec" && passwd=="123")
    {
        //跳到智能家居主界面
        //创建主界面的对象
        mainwin *newwin=new mainwin(this); //this指针为了方便等一会返回登录界面
        connect(this,SIGNAL(mysignal(QString,QString)),newwin,SLOT(fun(QString,QString)));
        //发送信号
        emit mysignal(name,passwd);
        //显示主界面
        newwin->show();
        //登录界面隐藏
        this->hide();
    }

}

#include "mainwin.h"
#include "ui_mainwin.h"
#include "airca.h"
#include "contlamp.h"

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

void mainwin::on_pushButton_clicked()
{
    //创建空调界面的对象
    Airca *newwin=new Airca(this); //this指针为了方便等一会返回菜单界面
    //显示主界面
    newwin->show();
    //空调界面隐藏
    this->hide();
}

void mainwin::on_pushButton_2_clicked()
{
    //创建灯界面的对象
    ContLamp *newwin=new ContLamp(this); //this指针为了方便等一会返回菜单界面
    //显示主界面
    newwin->show();
    //主界面关闭
    this->close();
}

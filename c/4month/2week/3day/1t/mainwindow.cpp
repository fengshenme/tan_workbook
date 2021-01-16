#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //在构造函数中初始化led
    ledfd=::open("/dev/led_drv",O_RDWR);  // ::告诉编译器open函数不属于MainWindow的成员函数
    if(ledfd==-1)
    {
        ::perror("打开led失败!\n");
        return;
    }
}

MainWindow::~MainWindow()
{
    //在析构函数中关闭led
    ::close(ledfd);
    delete ui;
}
//开灯按钮--》开8号灯
void MainWindow::on_startbt_clicked()
{
    //给led的驱动发送指令控制8号灯
    char buf[2]={0};
    buf[0]=1; //灯开
    buf[1]=8; //8号灯
    ::write(ledfd,buf,2);
}

void MainWindow::on_startbt_2_clicked()
{
    char buf[2]={0};
    buf[0]=1; //灯开
    buf[1]=9; //9号灯
    ::write(ledfd,buf,2);
}

void MainWindow::on_startbt_3_clicked()
{
    char buf[2]={0};
    buf[0]=1; //灯开
    buf[1]=10; //10号灯
    ::write(ledfd,buf,2);
}


//关灯按钮--》关8号灯
void MainWindow::on_closebt_clicked()
{
    //给led的驱动发送指令控制8号灯
    char buf[2]={0};
    buf[0]=0; //灯灭
    buf[1]=8;
    ::write(ledfd,buf,2);
}

void MainWindow::on_closebt_2_clicked()
{
    //给led的驱动发送指令控制8号灯
    char buf[2]={0};
    buf[0]=0; //灯灭
    buf[1]=9; //8号灯
    ::write(ledfd,buf,2);
}

void MainWindow::on_closebt_3_clicked()
{
    //给led的驱动发送指令控制8号灯
    char buf[2]={0};
    buf[0]=0; //灯灭
    buf[1]=10; //8号灯
    ::write(ledfd,buf,2);
}


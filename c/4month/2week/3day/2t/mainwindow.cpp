#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //在构造函数中初始化led
    ledfd=::open("/dev/led_drv",O_RDWR);  // ::告诉编译器open函数不属于MainWindow的成员函数
    if(ledfd==-1)
    {
        ::perror("打开led失败!\n");
        return;
    }

    // 初始化定时器
    qtime = new QTimer(this);
    qtime->setInterval(1000);
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));

}

MainWindow::~MainWindow()
{
    //在析构函数中关闭led
    ::close(ledfd);

    delete ui;
}


void MainWindow::timeFunc()
{

    //给led的驱动发送指令控制8号灯
    char buf[2]={0};


    //给led的驱动发送指令控制led灯
    for (i = 8; i < 11 ; i++) {
        buf[0]=1; //灯开
        buf[1]=i; //8号灯
        ::write(ledfd,buf,2);
        QThread::usleep(1000*500);
    }

    for (; i > 7 ; i--) {
        buf[0]=0; //灯
        buf[1]=i; //8号灯
        ::write(ledfd,buf,2);
        QThread::usleep(1000*500);
    }


}

void MainWindow::on_pushButton_clicked()
{
    qtime->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    qtime->stop();
}

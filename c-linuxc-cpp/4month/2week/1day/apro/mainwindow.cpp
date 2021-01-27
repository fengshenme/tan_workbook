#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化定时器
    qtime = new QTimer(this);
    qtime->setInterval(1000);

    qtime->start();
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));

}

MainWindow::~MainWindow()
{
    delete ui;
    qtime->stop();
}

 void MainWindow::timeFunc()
 {
    QTime time =  QTime::currentTime();
    QDate date = QDate::currentDate();
     qDebug() << date.toString("yyyy-MM-dd ") << time.toString("hh:mm:ss");

     QString str = QString("%1").arg(time.toString("hh:mm:ss.zzz"));
//     QString str = QString("%1").arg(time.toString("hh:mm:ss.zzz"));

     QString str2  = QString("%1").arg(date.toString("yyyy-MM-dd"));
     ui->lcdNumber->display(str);
     ui->lcdNumber_2->display(str2);
 }

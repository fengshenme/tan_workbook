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
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "sdf";

    MyDialog *mal = new MyDialog();

//    QLineEdit *usre = new QLineEdit(mal);

//    qDebug() << usre->text();
    mal->resize(500, 500);

//    usre->setGeometry(30,30, 100, 30);
    mal->show();



}


void MainWindow::timeFunc()
{

    qDebug("hello ") ;
    qDebug() << "www";

}


// 定时器启动
void MainWindow::on_pushButton_2_clicked()
{
    qtime->start();
}

// 定时器停止
void MainWindow::on_pushButton_3_clicked()
{
    qtime->stop();
}

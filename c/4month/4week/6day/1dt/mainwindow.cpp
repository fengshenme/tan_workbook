#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  mycam = new mycamera();
  mycam->camera_init();

  // 初始化定时器
  qtime = new QTimer(this);
  qtime->setInterval(50);
  //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
  connect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));
}

MainWindow::~MainWindow() {
  delete mycam;
  delete qtime;
  disconnect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));
  mycam->camera_uninit();

  delete ui;
}
//启动摄像头
void MainWindow::on_startbt_clicked() { qtime->start(); }
//关闭摄像头
void MainWindow::on_closebt_clicked() { qtime->stop(); }

void MainWindow::timeFunc() { mycam->camera_capture(); }

void MainWindow::on_pushButton_clicked() {}

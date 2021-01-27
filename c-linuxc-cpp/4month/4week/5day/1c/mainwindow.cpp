#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    foreach (const QCameraInfo &cameraInfo, cameras) {
        ui->comboBox->addItem(cameraInfo.deviceName());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startCam_clicked()
{


  //从下拉框中获取你点击的摄像头名字
  QString name=ui->comboBox->currentText();

  mycam=new QCamera(name.toUtf8());
  //准备好窗口
  QVideoWidget *win=new QVideoWidget(ui->widget);
  //调整窗口的大小,让它的大小跟widget大小一样
  win->resize(ui->widget->size());

  //设置摄像头跟显示的窗口绑定
  mycam->setViewfinder(win);

  //显示窗口
  win->show();
  //启动摄像头
  mycam->start();

}

void MainWindow::on_stopCam_clicked()
{
    mycam->stop();
}

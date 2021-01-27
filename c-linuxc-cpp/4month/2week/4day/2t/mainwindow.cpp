#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    thr = new MyThread(ui->label);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete thr;
}


void MainWindow::on_pushButton_clicked()
{
    thr->start();
}

void MainWindow::on_pushButton_2_clicked()
{
//    thr->terminate();
    thr->quit();
    thr->stop();
    if(thr->isFinished())
    {
        thr->wait();
    }

}

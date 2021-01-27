#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thr = new MyThread();
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

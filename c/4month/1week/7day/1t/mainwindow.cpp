#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(func()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::func()
{
    qDebug() << "自定义槽函数启动";
}


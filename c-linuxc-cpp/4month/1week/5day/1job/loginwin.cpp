#include "mainwindow.h"
#include "ui_mainwindow.h"

LoginWin::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

LoginWin::~MainWindow()
{
    delete ui;
}


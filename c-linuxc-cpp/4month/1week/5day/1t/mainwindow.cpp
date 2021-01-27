#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("你好");

    QLineEdit *qle = new QLineEdit(this);

    qle->setGeometry(30, 30, 80, 50);

    qle->setPlaceholderText("你好呀");

}

MainWindow::~MainWindow()
{
    delete ui;
}


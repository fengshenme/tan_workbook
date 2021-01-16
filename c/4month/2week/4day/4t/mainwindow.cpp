#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("服务端");

    serv =  new QTcpServer();

    serv->listen(QHostAddress(" 192.168.19.80"), 6869);
    connect(serv, SIGNAL(newConnection()), this, SLOT(func()));

}

MainWindow::~MainWindow()
{
    soc->close();
    delete ui;
}





void MainWindow::func()
{
    qDebug() << "--------------";
    soc = serv->nextPendingConnection();
    connect(soc, SIGNAL(readyRead()), this, SLOT(func2()));

}

void MainWindow::func2()
{
   QString aa =  QString(soc->readAll());
    qDebug() << aa;

    ui->textBrowser->setText(aa);
}

void MainWindow::on_pushButton_clicked()
{





}

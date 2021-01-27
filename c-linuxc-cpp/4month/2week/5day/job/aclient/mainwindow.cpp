#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("aclient");

    cli = new QTcpSocket();
    //
    cli->bind(QHostAddress::Any, 8080);
    // 连接服务器
    cli->connectToHost(QHostAddress("192.168.19.80"), 6869);


    connect(cli, SIGNAL(readyRead()), this, SLOT(func2()));
}

MainWindow::~MainWindow()
{
    cli->close();
    delete ui;

}

void MainWindow::func2()
{
    QString aa =  QString(cli->readAll());
    qDebug() << aa;
    ui->textBrowser->setText(aa);
}


void MainWindow::on_pushButton_clicked()
{
    QString stra = "192.168.19.80:8081-";
    QString str =  ui->textEdit->toPlainText();

    QString tmp = stra + str;
     qDebug() << "成功发送字节数:" << cli->write(tmp.toUtf8());

    ui->textEdit->clear();
    qDebug() << tmp ;

}



void MainWindow::on_btconnect_clicked()
{

}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket();
    if(udpSocket->bind(QHostAddress::AnyIPv4, 8080))
    {
        qDebug() << "绑定成功";
    }

    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::readFun);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete udpSocket;
}


void MainWindow::on_pushButton_clicked()
{
    QString qstr = ui->textEdit->toPlainText();
    int ret = udpSocket->writeDatagram(qstr.toUtf8(), qstr.toUtf8().size(), QHostAddress("192.168.19.80"), 8181);
    ui->textEdit->clear();
    qDebug() << "发送成功字节数:" << ret;

}

void MainWindow::readFun()
{
    char str[256] = {0};
    QHostAddress add;
    quint16 port ;
    udpSocket->readDatagram(str, 256, &add, &port);

    ui->textBrowser->setText(str);
    qDebug() << add << port;

}

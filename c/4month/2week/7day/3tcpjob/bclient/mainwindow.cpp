#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("bclient");

    cli = new QTcpSocket();
    //
    if(cli->bind(QHostAddress::Any, 8181))
    {
        qDebug() << "bind success...";
    }

    // 连接服务器
//    cli->connectToHost(QHostAddress("192.168.19.80"), 6869);
    cli->connectToHost(QHostAddress("127.0.0.1"), 6869);

    stra = QString("%1%2%3").arg("127.0.0.1").arg(":").arg("6869:")  ;
//    stra = QString("%1%2%3").arg("192.168.19.80").arg(":").arg("6869:")  ;

    connect(cli, SIGNAL(readyRead()), this, SLOT(func2()));


}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::func2()
{
    QByteArray bty =  cli->readAll();
    QString aa = QString(bty);

    QString stprex = aa.section(':', 0, 0);
    qDebug() << stprex;
    if(stprex == "getlist")
    {
        ui->listWidget->clear();
        QStringList  stelist = aa.section(':', 1).split("\n");
        int i;
        for(i = 0; i < stelist.size(); i++)
        {
           ui->listWidget->addItem( stelist.at(i));
        }
    }

    emit messgo(bty);

    qDebug() << aa << "接收字节数:" << bty.size();
}



void MainWindow::on_refuse_clicked()
{
    QString tmp = "m:getlist";
    qDebug() << "成功发送字节数:" << cli->write(tmp.toUtf8());
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
       stra = item->text() + ":";

       ui->label_2->setText(QString("选择与%1聊天").arg(stra));

       ChatDialog *mal = new ChatDialog(this , item->text(), cli);

       connect(this, &MainWindow::messgo, mal, &ChatDialog::to_msg);

       mal->setAttribute(Qt::WA_DeleteOnClose);
       mal->show();

}



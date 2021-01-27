#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("cclient");

    cli = new QTcpSocket();
    //
    if(!cli->bind(QHostAddress::Any, 8080))
    {
        qDebug() << "bind failed...";
    }
    // 连接服务器
    cli->connectToHost(QHostAddress("192.168.19.80"), 6869);

    stra = QString("%1%2%3").arg("192.168.19.80").arg(":").arg("6869:")  ;

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

    QString stprex = aa.section(':', 0, 0);
    qDebug() << stprex;
    if(stprex == "getlist")
    {
        QStringList  stelist = aa.section(':', 1).split("\n");
        int i;
        for(i = 0; i < stelist.size(); i++)
        {
           ui->listWidget->addItem( stelist.at(i));
        }

    }
    qDebug() << aa;
    ui->textBrowser->setText(aa);
}


void MainWindow::on_pushButton_clicked()
{

    QString str =  ui->textEdit->toPlainText();

    QString tmp = stra + str;
//    tmp = tmp.section(":",3, 4);
    qDebug() << "成功发送字节数:" << cli->write(tmp.toUtf8());

    ui->textEdit->clear();
    qDebug() << tmp ;

}



void MainWindow::on_refuse_clicked()
{
    QString tmp = "getlist";
    qDebug() << "成功发送字节数:" << cli->write(tmp.toUtf8());
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
       stra = item->text() + ":";

       ui->label_2->setText(QString("选择与%1聊天").arg(stra));

}

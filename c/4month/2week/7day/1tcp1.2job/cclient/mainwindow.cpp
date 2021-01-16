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
    if(cli->bind(QHostAddress::Any, 8080))
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

void MainWindow::on_test_clicked()
{

//    ChatThread ct;
//    cth = &ct;
//        cth = new ChatThread();
//    cth->run();
//    cth->start();
//    qDebug() << "crr" << cth->idealThreadCount();
//    connect(cth->mal, SIGNAL( windelsignal()), this, SLOT(delcat()));
//     connect(cth, &ChatThread::finished, cth, &QObject::deleteLater);
//    cth->quit();
//    cth->wait();

//    cli->close();

    ChatDialog *mal = new ChatDialog(this , stra, cli);

    connect(this, &MainWindow::messgo, mal, &ChatDialog::to_msg);

    mal->setAttribute(Qt::WA_DeleteOnClose);
    mal->show();

}

void MainWindow::delcat()
{
    emit cth->destroyed();
//    cth->terminate();
//    cth->wait();

//     cth->deleteLater();
    qDebug() << "free..";
}

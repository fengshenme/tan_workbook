#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("server");

    serv =  new QTcpServer();

    serv->listen(QHostAddress(" 192.168.19.82"), 6869);
    connect(serv, SIGNAL(newConnection()), this, SLOT(func()));

    listck = new QList<QTcpSocket *>();

}

MainWindow::~MainWindow()
{
    soc->close();
    delete ui;
    delete serv;
    delete listck;
}





void MainWindow::func()
{

    soc = serv->nextPendingConnection();
    connect(soc, SIGNAL(readyRead()), this, SLOT(func2()));
     qDebug() << soc->peerAddress().toString()<< soc->peerPort();
     QString str = QString("%1:%2").arg(soc->peerAddress().toString()).arg(soc->peerPort());

     listck->append(soc);

     ui->listWidget->addItem(str);

}

void MainWindow::func2()
{
   QString str =  QString(soc->readAll());



   qDebug() << str;
     // 通过字符-拆分字符串
    qDebug() << "正文" << str.section('-', 1, 1);
    qDebug() << "ip:" << str.section('-', 0, 0);
    qDebug() << str;
    ui->textBrowser->setText(str);

    int i;
    QString strt;
    for (i = 0; i < listck->size()-1 ; i++ ) {

         strt = QString("%1:%2").arg(listck->at(i)->peerAddress().toString()).arg(listck->at(i)->peerPort());
        if(strt == str.section('-', 0, 0))
        {
            soc = listck->at(i);
            soc->write(str.section('-', 1, 1).toUtf8());
            break;
        }

    }
    ui->label_2->setText(str);

//    soc = nullptr;


}

void MainWindow::on_pushButton_clicked()
{

    QString str =  ui->textEdit->toPlainText();

    soc->write(str.toUtf8());

    ui->textEdit->clear();
    qDebug() << str;


}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int i;
    QString str;
    for (i = 0; i < listck->size()-1 ; i++ ) {

         str = QString("%1:%2").arg(listck->at(i)->peerAddress().toString()).arg(listck->at(i)->peerPort());
        if(str == item->text())
            break;
    }
    ui->label_2->setText(str);
    soc = listck->at(i);

}

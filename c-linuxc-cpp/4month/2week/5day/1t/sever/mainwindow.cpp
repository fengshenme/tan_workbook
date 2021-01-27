#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("server");

    serv =  new QTcpServer();

    serv->listen(QHostAddress("192.168.19.80"), 6869);
    connect(serv, &QTcpServer::newConnection, this, &MainWindow::func);

    map = new QMap<QString, QTcpSocket *>;


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
    connect(soc,  &QIODevice::readyRead, this, &MainWindow::func2);
     QString str = QString("%1:%2").arg(soc->peerAddress().toString()).arg(soc->peerPort());
     qDebug() <<  str;

     map->insert(str, soc);

     ui->listWidget->addItem(str);

}

void MainWindow::func2()
{
   QString str ;

   QMap<QString, QTcpSocket *>::Iterator tmp;
   for (tmp = map->begin(); tmp != map->end(); tmp++ ) {
       str =  QString(tmp.value()->readAll());
       if(!str.isEmpty())
           break;
   }

   if(str.isEmpty())
   {
       qDebug() << "没有读取到数据" ;
       qDebug() << soc->readAll();
       return ;
   }
   qDebug() << str;
     // 通过字符-拆分字符串
    qDebug() << "正文" << str.section('-', 1, 1);
    qDebug() << "ip:" << str.section('-', 0, 0);
    ui->textBrowser->setText(str);

    if(map->value(str.section('-', 0, 0)) == 0)
    {
        qDebug() << "没有连接:-----------";
        return ;
    }
        qDebug() << "成功发送字节数:" << map->value(str.section('-', 0, 0))->write(str.section('-', 1, 1).toUtf8());


//    ui->label_2->setText(str);

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
    soc = map->value(item->text());
}

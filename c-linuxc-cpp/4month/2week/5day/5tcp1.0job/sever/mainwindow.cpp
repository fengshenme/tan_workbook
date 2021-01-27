#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    uselist.clear();
    setWindowTitle("server");

    serv =  new QTcpServer();

    if(!serv->listen(QHostAddress("192.168.19.80"), 6869))
    {
        qDebug() << "listen prot failed";
    }

    connect(serv, &QTcpServer::newConnection, this, &MainWindow::func);

    map = new QMap<QString, QTcpSocket *>;


}

MainWindow::~MainWindow()
{
    soc->close();
    delete ui;
    delete serv;

}





void MainWindow::func()
{

    soc = serv->nextPendingConnection();
    connect(soc,  &QIODevice::readyRead, this, &MainWindow::func2); // 数据来的信号时执行的函数
     QString str = QString("%1:%2").arg(soc->peerAddress().toString()).arg(soc->peerPort());
     qDebug() <<  str;

     connect(soc,  &QAbstractSocket::disconnected, this, &MainWindow::discont);  // 断开连接收到信号执行的槽函数

     uselist.append(str);
     uselist.append("\n");

     map->insert(str, soc);

     ui->listWidget->addItem(str);

}

void MainWindow::func2()
{

   QTcpSocket * dissock = qobject_cast<QTcpSocket *> (sender());
   QString str = dissock->readAll();

   if(str.isEmpty())
   {
       qDebug() << "没有读取到数据" ;
       qDebug() << soc->readAll();
       return ;
   }


   qDebug() << str;
   QString stprex;
//   if(str.indexOf('f') == 0)
//   {

//   }
//   else
//   {


//   }

    stprex = str.section(':', 0, 1);
     // 通过字符':' 拆分字符串
    qDebug() << "正文: " << str.section(':', 2);
    qDebug() << "ip:" << stprex;



    if( stprex == "getlist")
    {
         qDebug() << "成功发送字节数:" << dissock->write(("getlist:" + uselist).toUtf8());
         return ;
    }
    QString tmp = QString("%1:%2:%3").arg(dissock->peerAddress().toString()).arg(dissock->peerPort()).arg(str.section(':', 2));
    ui->textBrowser->setText(str);

    if(map->value(stprex) == 0)
    {
        qDebug() << "没有连接:-----------";
        return ;
    }

    qDebug() << "成功发送字节数:" << map->value(stprex)->write(tmp.toUtf8());

//    ui->label_2->setText(str);
//    soc = nullptr;

}

void MainWindow::discont()
{

    QTcpSocket * dissock = qobject_cast<QTcpSocket *> (sender());
    QString str = QString("%1:%2").arg(dissock->peerAddress().toString()).arg(dissock->peerPort());
    qDebug() <<  str;

    map->remove(str);
    uselist.replace(str+"\n", "");

    // 群发用户下线通知
    QMap<QString, QTcpSocket *>::Iterator tmp;
    for (tmp = map->begin(); tmp != map->end() ; tmp++ ) {
        tmp.value()->write(("getlist:" + uselist).toUtf8());
    }
    // 更新服务端用户列表显示
    QList<QListWidgetItem *> res= ui->listWidget->findItems(str, Qt::MatchStartsWith);
    ui->listWidget->takeItem(ui->listWidget->row(res.at(0)));

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

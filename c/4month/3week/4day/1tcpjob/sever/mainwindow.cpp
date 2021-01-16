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
//    if(!serv->listen(QHostAddress("127.0.0.1"), 6869))
    {
        qDebug() << "listen prot failed";
    }
    load_data();
    connect(serv, &QTcpServer::newConnection, this, &MainWindow::func);

    map = new QMap<QString, QTcpSocket *>;


}

MainWindow::~MainWindow()
{
    soc->close();
    delete ui;
    delete serv;

}

bool MainWindow::load_data()
{
    QFile file("H:/git-repo/qtdata/use.txt");

    bool ret = file.open(QIODevice::ReadOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
        file.close();
        return false;
    }

    QString str = QString(file.readAll());

    QStringList slit = str.split("\n");
    int i;
    for ( i = 0; i < slit.size(); ++i)
    {
        qDebug() << slit.at(i);
        if(!slit.at(i).isEmpty())
            usedb.insert(slit.at(i).section(":", 0, 0), slit.at(i));
    }


    file.close();

    return true;

}

bool MainWindow::save_use(QString use)
{

    qDebug() << use;

    if(usedb.value(use.section(':', 0, 0),  "0") != "0")
    {
        qDebug() <<  "用户名已注册";
        return false;
    }

    QFile file("H:/git-repo/qtdata/use.txt");

    bool ret = file.open(QIODevice::WriteOnly | QIODevice::Append);

    if(!ret)
    {
        qDebug() << "打开文件失败";
        file.close();
        return false;
    }

    int count = file.write(use.toUtf8());
    file.close();
    if(count > 0)
    {
        usedb.clear();
        load_data();
        return true;
    }
    else
    {
        return false;
    }


}

bool MainWindow::re_use(QString use)
{
    QString name = use.section(':', 0, 0);
    if(usedb.value(name,  "0") == "0")
    {
        qDebug() <<  "用户名不存在";
        return false;
    }

    usedb.remove(name);
    use.replace("\n", "");
    usedb.insert(name, use);

    QFile file("H:/git-repo/qtdata/use.txt");

    bool ret = file.open(QIODevice::WriteOnly );

    if(!ret)
    {
        qDebug() << "打开文件失败";
        file.close();
        return false;
    }

    int count = 0;
    QMap<QString, QString>::iterator tmp;
    for (tmp = usedb.begin(); tmp != usedb.end() ; tmp++ )
    {
        qDebug() << tmp.value();
        file.write((tmp.value() + "\n").toUtf8());
        count++;

    }

    file.close();
    if(count == usedb.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}





void MainWindow::func()
{

    soc = serv->nextPendingConnection();
    connect(soc,  &QIODevice::readyRead, this, &MainWindow::func2); // 数据来的信号时执行的函数
    QString str = QString("%1:%2").arg(soc->peerAddress().toString()).arg(soc->peerPort());
    qDebug() <<  str;

    connect(soc, &QAbstractSocket::disconnected, this, &MainWindow::discont);  // 断开连接收到信号执行的槽函数

    uselist.append(str);
    uselist.append("\n");

    map->insert(str, soc);

    ui->listWidget->addItem(str);

}

void MainWindow::func2()
{

    QTcpSocket * dissock = qobject_cast<QTcpSocket *> (sender());


    QByteArray bty = dissock->readAll();

    QString str = QString(bty);
    if(str.isEmpty())
    {
        qDebug() << "没有读取到数据" ;
        qDebug() << soc->readAll();
        return ;
    }


    //   qDebug() << str.size();
    //   qDebug() << str.section(':', 0, 3);


    QString stprex; //  QByteArray QByteArray::fromHex(const QByteArray &hexEncoded)
    stprex = str.section(':', 1, 2);
    // 通过字符':' 拆分字符串
    qDebug() << "正文: " << str.section(':', 3);
    qDebug() << "ip:" << stprex;
    if( stprex == "getlist")
    {
        qDebug() << "成功发送字节数:" << dissock->write(("getlist:" + uselist).toUtf8());
        return ;
    }
    else if( str.section(':', 0, 1) == "m:login" )
    {
        qDebug() << "----" << str.section(':', 2, 3);
// 先检测用户是否已注册,再比对密码是否正确
        if(usedb.value(str.section(':', 2, 2),  "0") != "0"
               && str.section(':', 3, 3) == usedb.value(str.section(':', 2, 2),  "0").section(':', 1, 1))
            qDebug() << "成功发送字节数:" << dissock->write(QString("m:login:true:").toUtf8());
        else
            qDebug() << "成功发送字节数:" << dissock->write(QString("m:login:false:").toUtf8());

        return ;
    }
    else if(str.section(':', 0, 1) == "m:register")
    {
        if(save_use(str.section(':', 2)))
           qDebug() << "成功发送字节数:" << dissock->write(QString("m:register:true:").toUtf8());
        else
            qDebug() << "成功发送字节数:" << dissock->write(QString("m:register:false:").toUtf8());

        return;
    }
    else if(str.section(':', 0, 1) == "m:repass")
    {
        if(re_use(str.section(':', 2)))
            qDebug() << "成功发送字节数:" << dissock->write(QString("m:repass:true:").toUtf8());
        else
            qDebug() << "成功发送字节数:" << dissock->write(QString("m:repass:false:").toUtf8());

        return;
    }
    else if( str.section(':', 0, 1) == "m:heport")
    {
        QString fileName = "H:/sharecode/yueqian/assest/fengjingtu-jpg/20.jpg";
        QFile file(fileName);

        bool ret = file.open(QIODevice::ReadOnly);

        if(!ret)
        {
            qDebug() << "打开文件失败";
            return;
        }
        QByteArray qarr =  file.readAll();

        file.close();
        qDebug() << "文件大小:" << qarr.size();
        QStringList list1 = fileName.split('/');
        qDebug() << list1[list1.size()-1];
        // 第一段字符代表上传的文件, 第二段字符是ip和端口识别, 第三段是是文件名及后缀, 第四段是数据
        QByteArray byar = QString( "f:heport:" + list1[list1.size()-1] + ":").toUtf8();

        byar.append(qarr);
        dissock->write(byar, byar.size());

        //    上传文件大小
        qDebug() << byar.size();
        return ;
    }

    QString tmp;
    if(map->value(stprex) == 0)
    {
        qDebug() << "没有连接:-----------";
        return ;
    }
    else if(str.section(':', 0, 0) == "f")
    {
        // 第一段字符代表上传的文件, 第二段字符是ip和端口识别, 第三段是是文件名及后缀, 第四段是数据
        tmp = QString("f:%1:%2:%3:").arg(dissock->peerAddress().toString()).arg(dissock->peerPort()).arg(str.section(':', 3, 3));

        QByteArray byar = bty.mid(str.section(':', 0, 3).toUtf8().size() + 1);
        // 转发文件大小
        qDebug() << "文件大小:" << byar.size();
        qDebug() << "成功发送字节数:" << map->value(stprex)->write(tmp.toUtf8().append(byar));
        ui->textBrowser->setText(str);
    }
    else if(str.section(':', 0, 0) == "m")
    {
        tmp = QString("m:%1:%2:%3").arg(dissock->peerAddress().toString()).arg(dissock->peerPort()).arg(str.section(':', 3));
        ui->textBrowser->setText(str);
        qDebug() << "成功发送字节数:" << map->value(stprex)->write(tmp.toUtf8());
    }


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

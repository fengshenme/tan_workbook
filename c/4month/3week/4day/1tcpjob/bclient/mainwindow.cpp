#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QTcpSocket *cl)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("8181");

    this->cli = cl;

    // 初始化定时器
    qtime = new QTimer(this);
    qtime->setInterval(1000);

    qtime->start();
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));

    //定义请求对象
    QUrl url("http://www.weather.com.cn/data/cityinfo/101280101.html");
    QNetworkRequest req(url);
    //发送该请求给服务器
    manager.get(req);

    //关联finished信号
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(weather(QNetworkReply*)));

}

MainWindow::~MainWindow()
{

    delete ui;

    if(qtime != NULL )
    {
        qDebug() << "析构qtime";
        qtime->stop();
       delete qtime;
       qtime = NULL;
    }


}

void MainWindow::func2(QByteArray msg)
{
    QByteArray bty =  msg;
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



void MainWindow::on_logout_clicked()
{

    QFile file("H:/git-repo/qtdata/state.txt");

    bool ret = file.open(QIODevice::WriteOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
        file.close();
    }
    QString strstat = "0";
    qDebug() << file.write(strstat.toUtf8());
    file.close();
    this->parentWidget()->show();
    this->close();

}

void MainWindow::timeFunc()
{
    QTime time =  QTime::currentTime();
    QDate date = QDate::currentDate();
//    qDebug() << date.toString("yyyy-MM-dd ") << time.toString("hh:mm:ss");

    QString str = QString("%1").arg(time.toString("hh:mm:ss"));
    //     QString str = QString("%1").arg(time.toString("hh:mm:ss.zzz"));

    QString str2  = QString("%1").arg(date.toString("yyyy-MM-dd "));
    ui->lcdNumber->display(str2+str);

}

void MainWindow::weather(QNetworkReply* reply)
{
    //读取服务器回复的应答信息
    QByteArray buf=reply->readAll(); //buf里面存放就是从网上获取的天气预报信息(json数据)
    //定义json解析错误对象
    QJsonParseError err;
    //把网络上得到的json标准化存储
    //{"weatherinfo":{"city":"北京","cityid":"101010100","temp1":"18℃","temp2":"31℃","weather":"多云转阴","img1":"n1.gif","img2":"d2.gif","ptime":"18:00"}}
    QJsonDocument mydoc=QJsonDocument::fromJson(buf,&err);
    //判断要解析的json数据是否合法
    if(err.error!=QJsonParseError::NoError)
    {
        qDebug()<<"json数据有问题: "<<err.errorString();
        return;
    }
    QJsonObject obj=mydoc.object();
    QJsonValue val=obj.value("weatherinfo");
    QJsonObject otherobj=val.toObject();

    QString city = otherobj.find("city").value().toString();
    QString max = otherobj.find("temp1").value().toString();
    QString min = otherobj.find("temp2").value().toString();

    QJsonObject::Iterator tmp;
    for (tmp = otherobj.begin(); tmp != otherobj.end() ; tmp++ ) {
        qDebug() << tmp.key() << ":" << tmp.value().toString();
    }



    //在文本浏览框中显示天气预报信息
        ui->label_3->setText(QString("城市:%1 今日最高温:%2 今日最低温:%3").arg(city).arg(max).arg(min));
}

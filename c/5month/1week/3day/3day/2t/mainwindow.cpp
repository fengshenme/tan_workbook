#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义请求对象
    QUrl url("http://wthrcdn.etouch.cn/weather_mini?city=广州");
    QNetworkRequest req(url);
    //发送该请求给服务器
    manager.get(req);
    //关联finished信号
    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(weather(QNetworkReply*)));

    //发送该请求给服务器-获取时间
    manager2.get(QNetworkRequest(QUrl("http://quan.suning.com/getSysTime.do")));
    connect(&manager2, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTime(QNetworkReply*)));

    //    ui->nextpt->setStyleSheet("border-image: url(:/new/prefix1/img/next.jpg);");
    //    ui->prevbt->setStyleSheet("border-image: url(:/new/prefix1/img/prev.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete qtime;
}

void MainWindow::timeFunc()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    //    qDebug() << date.toString("yyyy-MM-dd ") << time.toString("hh:mm:ss");

    QString str = QString("%1").arg(time.toString("hh:mm:ss"));
    //     QString str = QString("%1").arg(time.toString("hh:mm:ss.zzz"));

    QString str2 = QString("%1").arg(date.toString("yyyy-MM-dd "));
    ui->lcdTime->display(str2 + str);
}

void MainWindow::weather(QNetworkReply* reply)
{
    //读取服务器回复的应答信息
    QByteArray buf = reply->readAll(); //buf里面存放就是从网上获取的天气预报信息(json数据)
    //定义json解析错误对象
    QJsonParseError err;
    //把网络上得到的json标准化存储
    QJsonDocument mydoc = QJsonDocument::fromJson(buf, &err);
    //判断要解析的json数据是否合法
    if (err.error != QJsonParseError::NoError) {
        qDebug() << "json数据有问题: " << err.errorString();
        return;
    }
    QJsonObject obj = mydoc.object();
    QJsonValue val = obj.value("data");
    QJsonObject otherobj = val.toObject();
    QJsonValue val2 = otherobj.value("forecast");
    QJsonArray arr = val2.toArray();
    QJsonObject des = arr[0].toObject();

    QString city = otherobj.value("city").toString();

    QString max = des.find("high").value().toString();
    QString min = des.find("low").value().toString();
    QString fengli = des.find("fengli").value().toString().section("[", 2, 2).replace("]]>", "");
    QString fengxiang = des.find("fengxiang").value().toString();
    QString stype = des.find("type").value().toString();

    //在文本浏览框中显示天气预报信息
    ui->weather->setText(QString("%1 %2 %3 %4 %5 %6")
                             .arg(city)
                             .arg(stype)
                             .arg(max)
                             .arg(min)
                             .arg(fengxiang)
                             .arg(fengli));
}

void MainWindow::getTime(QNetworkReply* reply)
{
    //    // 获取网络时间的方法
    //    QTcpSocket* socket = new QTcpSocket();
    //    socket->connectToHost("time.nist.gov", 13);
    //    if (socket->waitForConnected()) {
    //        if (socket->waitForReadyRead()) {
    //            QString str(socket->readAll());
    //            str = str.trimmed();
    //            qDebug() << str;
    //            str = str.section(" ", 1, 2);
    //            qDebug() << str;
    //        }
    //    }
    //    socket->close();
    //    delete socket;

    //读取服务器回复的应答信息
    QByteArray buf = reply->readAll(); //buf里面存放就是从网上获取的天气预报信息(json数据)

    //定义json解析错误对象
    QJsonParseError err;
    //把网络上得到的json标准化存储
    QJsonDocument mydoc = QJsonDocument::fromJson(buf, &err);

    //判断要解析的json数据是否合法
    if (err.error != QJsonParseError::NoError) {
        qDebug() << "json数据有问题: " << err.errorString();
        return;
    }
    QJsonObject obj = mydoc.object();
    QString val = obj.value("sysTime2").toString();
    qDebug() << val;
    QOperatingSystemVersion::OSType ost = QOperatingSystemVersion::currentType();
    //不是windos系统不是mac系统时则认为是linux系统
    if (ost != QOperatingSystemVersion::Windows && ost != QOperatingSystemVersion::MacOS) {
        // 同步系统时间 保存配置
        QString date = QString("date -s \"%1\";hwclock -w ;sync").arg(val);
        qDebug() << date;
        QProcess::startDetached(date);
    }

    // 初始化定时器
    qtime = new QTimer(this);
    qtime->setInterval(1000);

    qtime->start();
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));
}

// 管理员登陆
void MainWindow::on_adminloginbt_clicked()
{
    AdminLogin* adlogin = new AdminLogin(this);
    adlogin->show();

    this->hide();
}

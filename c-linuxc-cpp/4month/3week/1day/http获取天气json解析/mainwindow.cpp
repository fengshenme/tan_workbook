#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //关联finished信号
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(fun(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//获取天气预报的按钮
void MainWindow::on_downbt_clicked()
{
    //获取输入框中输入的天气预报网址
    QString path=ui->lineEdit->text();
    //定义请求对象
    QUrl url(path);
    QNetworkRequest req(url);
    //发送该请求给服务器
    manager.get(req);
}
//槽函数中接收信息
void MainWindow::fun(QNetworkReply* reply)
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

    //剥洋葱，一步步解析json
    //obj里面"weatherinfo":{"city":"北京","cityid":"101010100","temp1":"18℃","temp2":"31℃","weather":"多云转阴","img1":"n1.gif","img2":"d2.gif","ptime":"18:00"}
    QJsonObject obj=mydoc.object();
    //再解析得到weatherinfo对应的值
    //此时返回值就是{"city":"北京","cityid":"101010100","temp1":"18℃","temp2":"31℃","weather":"多云转阴","img1":"n1.gif","img2":"d2.gif","ptime":"18:00"}
    QJsonValue val=obj.value("weatherinfo");
    QJsonObject otherobj=val.toObject();
    //再解析


    //在文本浏览框中显示天气预报信息
    ui->textBrowser->setText(buf);
}

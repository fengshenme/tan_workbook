#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    parking_sum = 80;

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

    QRegExp rx("parkingbt?");
    mblist = this->findChildren<ParkButton*>(rx);
    qDebug() << mblist.size();
    parkpos = 0;
    int var;
    for (var = 0; var < mblist.size(); ++var) {
        //        mblist.at(var)->setFlag(false);
        mblist.at(var)->setText(QString("%1").arg(var + 1));
        connect(this, &MainWindow::messgo, mblist.at(var), &ParkButton::card_nump);
    }

    updateParkSum();
    findParkingBay();

    mycam = new MyCamera();
    mycam->camera_init();

    // 视频定时器
    potoqtime = new QTimer(this);
    potoqtime->setInterval(50);
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(potoqtime, SIGNAL(timeout()), this, SLOT(swipingPo()));

    // 刷卡定时器
    cardqtime = new QTimer(this);
    cardqtime->setInterval(500);

    // 退出时,定时器需要停止
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(cardqtime, SIGNAL(timeout()), this, SLOT(readCard()));

    rf = new RFID();

    //打开串口文件
    fd = rf->open_serial();

    /*初始化串口*/
    rf->init_tty(fd);

    rf->timeout.tv_sec = 1;
    rf->timeout.tv_usec = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete qtime;
    delete mycam;
    delete potoqtime;
    disconnect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));
    disconnect(potoqtime, SIGNAL(timeout()), this, SLOT(swipingPo()));
    mycam->camera_uninit();
}

int MainWindow::updateParkSum()
{
    CardSql* csl = new CardSql();
    QSqlQuery qsq;
    QString cmd = QString("select count(*) from tb_card where parking_bay!='%1' ;").arg("0");
    int itmp = 0;

    if (csl->findCard(cmd, qsq) == 0) {
        qDebug() << qsq.size();

        if (qsq.first()) {

            //0- id,1-车牌 insignia, 2-卡号-card_num, 3-用户手机号 phone, 4-卡上余额 balance,5-逻辑删除 bflags,
            //6-充值记录 pay_rank, 7-消费记录purchase_log ,8-入库时间-begin_time, 9-出库时间-end_time,
            // 10-停车价格 stop_price,11-停车位置 parking_bay;
            itmp = qsq.value(0).toString().toInt(); //已占车位数
            qDebug() << itmp;
        }
        //        QMessageBox::information(this, "提示", "查询成功");
    } else {
        //        QMessageBox::critical(this, "提示", "查询失败");
        qDebug() << "查询失败";
    }

    delete csl;
    parking_sum -= itmp;
    ui->parkSumLabel->setText(QString("%1").arg(parking_sum));
    return 0;
}

int MainWindow::findParkingBay()
{
    CardSql* csl = new CardSql();
    QSqlQuery qsq;
    QString cmd = QString("select card_num,parking_bay from tb_card where parking_bay!='%1' ;").arg("0");
    if (csl->findCard(cmd, qsq) == 0) {
        qDebug() << qsq.size();

        while (qsq.next()) {

            //0- id,1-车牌 insignia, 2-卡号-card_num, 3-用户手机号 phone, 4-卡上余额 balance,5-逻辑删除 bflags,
            //6-充值记录 pay_rank, 7-消费记录purchase_log ,8-入库时间-begin_time, 9-出库时间-end_time,
            // 10-停车价格 stop_price,11-停车位置 parking_bay;
            qDebug() << qsq.value(0).toString();
            map.insert(qsq.value(0).toString(), qsq.value(1).toString());
        }
        //        QMessageBox::information(this, "提示", "查询成功");

    } else {
        //        QMessageBox::critical(this, "提示", "查询失败");
        qDebug() << "查询失败";
    }

    delete csl;

    return 0;
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
    //不是windos系统不是mac系统时则认为是linux系统
    // 同步系统时间 保存配置
    QString date = QString("date -s '%1'").arg(val);
    qDebug() << date;
    //    QProcess::startDetached(date);

    QByteArray ba = date.toUtf8();
    system(ba.data());
    system("hwclock -w ");
    system("sync");

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

void MainWindow::on_prevbt_pressed()
{
    ui->prevbt->setStyleSheet("background-color: rgb(136, 138, 133);");
}

void MainWindow::on_prevbt_released()
{
    ui->prevbt->setStyleSheet("border-image: url(:/new/prefix1/img/prev.jpg);");
}

void MainWindow::on_nextpt_pressed()
{
    ui->nextpt->setStyleSheet("background-color: rgb(136, 138, 133);");
}

void MainWindow::on_nextpt_released()
{
    ui->nextpt->setStyleSheet("border-image: url(:/new/prefix1/img/next.jpg);");
}

void MainWindow::on_swipingBt_clicked()
{

    //入库 开始时间
    QString begin_time = QString("%1:%2")
                             .arg(QDate::currentDate().toString("yy:MM:dd"))
                             .arg(QTime::currentTime().toString("hh:mm"));
    //    QString cardstr = "1610604932";
    //    QString cardstr = "1610604927";

    int var;
    for (var = 0; var < mblist.size(); ++var) {

        //        mblist.at(var)->setDisabled(false);
        foreach (QString parking, map.values()) {
            if (mblist.at(var)->text() == parking) {
                mblist.at(var)->setFlag(true);
            }
        }
    }
    cardqtime->start();
    ui->swipingBt->setText("请刷卡..");
}

void MainWindow::updateSum(bool bl)
{
    map.clear();
    findParkingBay();

    if (bl) {
        parking_sum--;
        qDebug() << "入库成功";
        //        potoqtime->start();

        //        potoqtime->stop();
        //        QMessageBox::information(this, "提示", "开始保存");
        mycam->save_pic();
        potoqtime->start();
        ui->swipingBt->setText(">请点击刷卡<");

    } else {

        qDebug() << "出库成功";
        parking_sum++;
        potoqtime->stop();
        //        QMessageBox::information(this, "提示", "开始保存");
        mycam->save_pic();
        ui->swipingBt->setText(">请点击刷卡<");
    }
    ui->parkSumLabel->setText(QString("%1").arg(parking_sum));
}

void MainWindow::on_nextpt_clicked()
{
    parkpos += 8;
    if (parkpos >= 80) {
        QMessageBox::information(this, "提示", "已经到最后页了");
        parkpos = 80;
        return;
    }
    qDebug() << parkpos;
    int var;
    for (var = 0; var < mblist.size(); ++var) {
        mblist.at(var)->setText(QString("%1").arg(var + parkpos + 1));
        mblist.at(var)->setFlag(false);
    }
    for (var = 0; var < mblist.size(); ++var) {

        foreach (QString parking, map.values()) {
            if (mblist.at(var)->text() == parking) {
                mblist.at(var)->setFlag(true);
            }
        }
    }
}

void MainWindow::on_prevbt_clicked()
{
    parkpos -= 8;
    if (parkpos < 0) {
        QMessageBox::information(this, "提示", "已经到第一页了");
        parkpos = 0;
        return;
    }
    qDebug() << parkpos;
    int var;
    for (var = 0; var < mblist.size(); ++var) {
        //        mblist.at(var)->setFlag(false);
        mblist.at(var)->setText(QString("%1").arg(var + parkpos + 1));
        mblist.at(var)->setFlag(false);
        //        connect(this, &MainWindow::messgo, mblist.at(var), &ParkButton::card_nump);
    }
    for (var = 0; var < mblist.size(); ++var) {

        foreach (QString parking, map.values()) {
            if (mblist.at(var)->text() == parking) {
                mblist.at(var)->setFlag(true);
            }
        }
    }
}

void MainWindow::swipingPo()
{
    mycam->camera_capture();
}

void MainWindow::readCard()
{
    //确保AB命令发送成功，并且模块响应成功，所以在写成定时器的曹函数
    int ret;

    //发送A命令
    ret = rf->PiccRequest(fd);
    if (ret == -1) //若是请求超时退出，必须要关闭串口后，重新打开才能再次读取数据
    {
        usleep(10000);
        rf->close_serial(fd);

        //打开串口文件
        fd = rf->open_serial();
        /*初始化串口*/
        rf->init_tty(fd);
        rf->timeout.tv_sec = 1;
        rf->timeout.tv_usec = 0;
        return;
    } else //(ret == 0)
    {
        printf("ok!\n");
    }
    //发送B命令 和获取卡号
    ret = rf->PiccAnticoll(fd);

    //若获取的cardid为0，或获取id超时，则需重新发送'A'命令
    if (rf->cardid == 0 || ret == -1)
        return;
    else if (ret == 0) {
        printf("card ID = %#x\n", rf->cardid); //打印cardid号

        //        ui->cardNum->setText(QString("%1").arg(rf->cardid));
        //        usleep(500000);
        // QString cardstr = "1610677313";
        cardqtime->stop();

        QString cardstr = QString("%1").arg(rf->cardid);
        ui->swipingBt->setText(cardstr);
        bool parflag = true;
        foreach (QString cardnum, map.keys()) {
            qDebug() << cardnum;
            if (cardstr == cardnum) {
                parflag = false;
                qDebug() << cardnum;
                break;
            }
        }

        // 1610604932 卡号
        // parflag 等于false是要出库,为ture是要入库
        emit messgo(cardstr, parflag);
    }

    return;
}

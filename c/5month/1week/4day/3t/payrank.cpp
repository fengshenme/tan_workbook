#include "payrank.h"
#include "ui_payrank.h"

PayRank::PayRank(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::PayRank)
{
    ui->setupUi(this);

    // 初始化定时器
    qtime = new QTimer(this);
    qtime->setInterval(500);

    // 退出时,定时器需要停止
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(readCard()));

    rf = new RFID();

    //打开串口文件
    fd = rf->open_serial();

    /*初始化串口*/
    rf->init_tty(fd);

    rf->timeout.tv_sec = 1;
    rf->timeout.tv_usec = 0;
}

//确保AB命令发送成功，并且模块响应成功，所以在写成定时器的曹函数
void PayRank::readCard()
{
    int ret;

    //发送A命令
    ret = rf->PiccRequest(fd);
    if (ret == -1) //若是请求超时退出，必须要关闭串口后，重新打开才能再次读取数据
    {
        usleep(500000);
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
        ui->cardNum->setText(QString("%1").arg(rf->cardid));
        //        usleep(500000);
        qtime->stop();
        findUse();
    }

    return;
}

PayRank::~PayRank()
{
    delete ui;
}

int PayRank::findUse()
{
    CardSql* csl = new CardSql();
    QSqlQuery qsq;
    QString cmd = QString("select * from tb_card where card_num='%1' ;").arg(ui->cardNum->text());
    if (csl->findCard(cmd, qsq) == 0) {
        qDebug() << qsq.size();

        if (qsq.first()) {

            id = qsq.value(0).toString();
            ui->insigniaLba->setText(qsq.value(1).toString()); //车牌号
            ui->cardNum->setText(qsq.value(2).toString()); // 卡号
            ui->oldPhoneLb->setText(qsq.value(3).toString()); // 手机号
            ui->balance_lab->setText(qsq.value(4).toString()); // 余额
            ui->pay_log_la->setText(qsq.value(6).toString()); // 充值记录
        }
        QMessageBox::information(this, "提示", "查询成功");
    } else {
        QMessageBox::critical(this, "提示", "查询失败");
    }

    delete csl;
    return 0;
}

void PayRank::on_prevBt_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void PayRank::on_readCardBt_clicked()
{

    qtime->start();
    ui->cardNum->setText("请放上停车卡");
}

void PayRank::on_insigniaFindBt_clicked()
{
    CardSql* csl = new CardSql();
    QSqlQuery qsq;
    QString cmd = QString("select * from tb_card where insignia='%1' ;").arg(ui->insigniaFindLe->text());
    if (csl->findCard(cmd, qsq) == 0) {
        qDebug() << qsq.size();

        if (qsq.first()) {

            //0- id,1-车牌 insignia, 2-卡号-card_num, 3-用户手机号 phone, 4-卡上余额 balance,5-逻辑删除 bflags,
            //6-充值记录 pay_rank, 7-消费记录purchase_log ,8-入库时间-begin_time, 9-出库时间-end_time,
            // 10-停车价格 stop_price,11-停车位置 parking_bay;
            id = qsq.value(0).toString();
            ui->insigniaLba->setText(qsq.value(1).toString()); //车牌号
            ui->cardNum->setText(qsq.value(2).toString()); // 卡号
            ui->oldPhoneLb->setText(qsq.value(3).toString()); // 手机号
            ui->balance_lab->setText(qsq.value(4).toString()); // 余额
            ui->pay_log_la->setText(qsq.value(6).toString()); // 充值记录
        }
        QMessageBox::information(this, "提示", "查询成功");
    } else {
        QMessageBox::critical(this, "提示", "查询失败");
    }

    delete csl;
}

void PayRank::on_delUse_clicked()
{

    if (id == nullptr || id.length() == 0) {
        QMessageBox::information(this, "提示", "请先查找用户");
        return;
    }

    CardSql* csl = new CardSql();

    QMessageBox::StandardButton ifl = QMessageBox::information(this, "提示", "是否要删除此用户!", QMessageBox::Ok | QMessageBox::Cancel);
    if (ifl == QMessageBox::Ok) {

        QString cmd = QString("delete from tb_card where id='%1' ;").arg(id);
        if (csl->delCard(cmd) == 0) {
            QMessageBox::information(this, "提示", "删除成功");
        } else {
            QMessageBox::critical(this, "提示", "删除失败");
        }
    } else if (ifl == QMessageBox::Cancel) {

        qDebug() << "Cancel";
    }

    delete csl;
}

void PayRank::on_update_insigniaBt_clicked()
{
    QString new_insignia = ui->new_insignia_le->text();

    CardSql* csl = new CardSql();
    // 粤a092333
    QMessageBox::StandardButton ifl = QMessageBox::information(this, "提示", "是否要更新车牌号!", QMessageBox::Ok | QMessageBox::Cancel);
    if (ifl == QMessageBox::Ok) {

        QString cmd = QString("update tb_card set insignia='%1' where id='%2';").arg(new_insignia).arg(id);
        if (csl->updateCard(cmd) == 0) {

            QMessageBox::information(this, "提示", "更新成功");
        } else {
            QMessageBox::critical(this, "提示", "更新失败");
        }
    } else if (ifl == QMessageBox::Cancel) {

        qDebug() << "Cancel";
    }

    delete csl;
}

void PayRank::on_update_phoneBt_clicked()
{
    QString new_phone = ui->new_phone_le->text();
    CardSql* csl = new CardSql();
    // 粤a092333
    QMessageBox::StandardButton ifl = QMessageBox::information(this, "提示", "是否要修改手机号!", QMessageBox::Ok | QMessageBox::Cancel);
    if (ifl == QMessageBox::Ok) {

        QString cmd = QString("update tb_card set phone='%1' where id='%2';").arg(new_phone).arg(id);
        if (csl->updateCard(cmd) == 0) {

            QMessageBox::information(this, "提示", "更新成功");
        } else {
            QMessageBox::critical(this, "提示", "更新失败");
        }
    } else if (ifl == QMessageBox::Cancel) {

        qDebug() << "Cancel";
    }
}

void PayRank::on_rechargeBt_clicked()
{

    QString money = ui->money_count->text();
    QString balancea = ui->balance_lab->text();

    if (money.toInt() <= 0) {
        QMessageBox::information(this, "提示", "充值金额需要大于0");
        return;
    }

    QString paylog = QString("%1%2%3:")
                         .arg(QDate::currentDate().toString("yyMMdd"))
                         .arg(QTime::currentTime().toString("hhmmss-"))
                         .arg(money);

    CardSql* csl = new CardSql();
    QString mont = QString("要充值%1元").arg(money);
    // 粤a092333
    QMessageBox::StandardButton ifl = QMessageBox::information(this, "提示", mont, QMessageBox::Ok | QMessageBox::Cancel);
    if (ifl == QMessageBox::Ok) {

        QString cmd = QString("update tb_card set balance=%1,pay_rank='%2' where id='%3';")
                          .arg(balancea.toDouble() + money.toDouble())
                          .arg(paylog)
                          .arg(id);

        if (csl->updateCard(cmd) == 0) {

            QMessageBox::information(this, "提示", "更新成功");
        } else {
            QMessageBox::critical(this, "提示", "更新失败");
        }
    } else if (ifl == QMessageBox::Cancel) {

        qDebug() << "Cancel";
    }
    ui->money_count->clear();
}

void PayRank::on_reissue_cardBt_clicked()
{
    QString cardnum = ui->cardNum->text();

    if (cardnum.length() > 0 && cardnum.toInt() > 0) {
        QMessageBox::information(this, "提示", "卡号不对");
        return;
    }
    qDebug() << cardnum;
    CardSql* csl = new CardSql();
    // 粤a092333
    QMessageBox::StandardButton ifl = QMessageBox::information(this, "提示", "是否补卡?", QMessageBox::Ok | QMessageBox::Cancel);
    if (ifl == QMessageBox::Ok) {

        QString cmd = QString("update tb_card set card_num=%1 where id='%2';").arg(cardnum).arg(id);
        if (csl->updateCard(cmd) == 0) {

            QMessageBox::information(this, "提示", "补卡成功");
        } else {
            QMessageBox::critical(this, "提示", "补卡失败");
        }
    } else if (ifl == QMessageBox::Cancel) {

        qDebug() << "Cancel";
    }
}

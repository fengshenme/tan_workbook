#include "parkbutton.h"

ParkButton::ParkButton(QWidget* parent)
    : QPushButton(parent)
{

    connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
    connect(this, SIGNAL(messSum(bool)), this->parentWidget()->parentWidget()->parentWidget(), SLOT(updateSum(bool)));

    pa = parent;
    flags = false;
}

int ParkButton::inCar()
{
    //入库 开始时间
    QString begin_time = QString("%1").arg(time(0));

    if (flags) {
        QMessageBox::information(pa, "提示", "请刷卡");
        return -1;
    }
    qDebug() << begin_time;
    CardSql* csl = new CardSql();
    // 粤a092333

    QString cmd = QString("update tb_card set parking_bay='%1',begin_time='%2' where card_num='%3';")
                      .arg(this->text())
                      .arg(begin_time)
                      .arg(card_num);

    if (csl->updateCard(cmd) == 0) {

        QMessageBox::information(pa, "提示", "入库成功");
        setFlag(true);
        emit messSum(true);
    } else {
        QMessageBox::critical(pa, "提示", "入库失败");
    }

    delete csl;
    return 0;
}

int ParkButton::outCar() // 出库
{
    //出库 开始时间
    QString end_time = QString("%1").arg(time(0));

    qDebug() << end_time;

    CardSql* csl = new CardSql();
    // 粤a092333

    QString cmd = QString("update tb_card set parking_bay='%1',end_time='%2' where card_num='%3';")
                      .arg("0")
                      .arg(end_time)
                      .arg(card_num);

    if (csl->updateCard(cmd) == 0) {

        //        QMessageBox::information(pa, "提示", "入库成功");

    } else {
        //        QMessageBox::critical(pa, "提示", "出库失败");
        //        qDebug() << "没有入库1a";
        //        delete csl;
        //        return 0;
    }

    delete csl;
    CardSql* csla = new CardSql();
    cmd = QString("select balance,begin_time,end_time from tb_card where card_num='%1';").arg(card_num);
    int price = 0;
    int bal = 0;
    QSqlQuery qsq;
    QString begin_time;
    if (csl->findCard(cmd, qsq) == 0) {
        qDebug() << qsq.size();

        if (qsq.first()) {

            bal = qsq.value(0).toString().toInt();
            int beg = qsq.value(1).toString().toInt();
            int end = qsq.value(2).toString().toInt();

            price = (end - beg); //测试1秒1元
            QString stt = QString("需支付%1元").arg(price);

            QMessageBox::information(pa, "提示", stt);
        }
    } else {
        //        QMessageBox::critical(pa, "提示", "查询失败");
    }

    cmd = QString("update tb_card set balance='%1' where card_num='%2';")
              .arg(bal - price)
              .arg(card_num);

    if (csla->updateCard(cmd) == 0) {

        //        QMessageBox::information(pa, "提示", "入库成功");
        qDebug() << bal - price;
        setFlag(false);
        emit messSum(false);
    } else {
        QMessageBox::critical(pa, "提示", "出库失败");
    }

    delete csla;
    return 0;
}

void ParkButton::on_clicked()
{

    //    if (flags) {
    //        QMessageBox::information(this, "提示", "车位已被使用");
    //        return -1;
    //    }
    CardSql* csl = new CardSql();
    // 粤a092333

    QString cmd = QString("select parking_bay from tb_card where card_num='%1';").arg(card_num);

    QSqlQuery qsq;
    QString begin_time;
    if (csl->findCard(cmd, qsq) == 0) {
        qDebug() << qsq.size();

        if (qsq.first()) {

            QString ats = qsq.value(0).toString();
            if (ats != "0" && ats != this->text()) {
                QMessageBox::information(pa, "提示", "请刷卡或这不是你的车");
                return;
            }
        }
    } else {
        QMessageBox::critical(pa, "提示", "请刷卡");
    }
    delete csl;

    if (parfl) {
        inCar();
    } else {
        outCar();
    }
}

void ParkButton::card_nump(QString cid, bool parflag)
{
    qDebug() << cid;
    card_num = cid;
    parfl = parflag;
}

void ParkButton::setFlag(bool bl)
{
    flags = bl;

    if (flags) {
        this->setStyleSheet("border-image: url(:/new/prefix1/img/car.jpg);");
    } else {
        this->setStyleSheet("background-color: rgb(255, 255, 255);");
    }
}

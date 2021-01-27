#include "parkbutton.h"

ParkButton::ParkButton(QWidget* parent)
    : QPushButton(parent)
{

    connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
    connect(this, SIGNAL(messSum(bool)), parent, SLOT(updateSum(bool)));

    pa = parent;
    flags = false;
}

int ParkButton::inCar()
{
    //入库 开始时间
    QString begin_time = QString("%1:%2")
                             .arg(QDate::currentDate().toString("yy:MM:dd"))
                             .arg(QTime::currentTime().toString("hh:mm"));

    if (flags) {
        QMessageBox::information(this, "提示", "车位已被使用");
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
        messSum(true);
    } else {
        QMessageBox::critical(pa, "提示", "入库失败");
    }

    return 0;
}

int ParkButton::outCar() // 出库
{
    return 0;
}

void ParkButton::on_clicked()
{
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
        this->setStyleSheet("background-color: rgb(136, 138, 133);;");
    }
}

#ifndef PARKBUTTON_H
#define PARKBUTTON_H

#include "cardsql.h"
#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QTime>

class ParkButton : public QPushButton {
    Q_OBJECT
public:
    ParkButton(QWidget* parent = nullptr);

    int inCar();
    int outCar();
signals:
    void messSum(bool bl);
public slots:
    void on_clicked();
    void card_nump(QString cid, bool parflag);
    void setFlag(bool bl);

private:
    QString card_num;
    QWidget* pa;
    bool flags;
    bool parfl; //判断是入库还是出库
};

#endif // PARKBUTTON_H

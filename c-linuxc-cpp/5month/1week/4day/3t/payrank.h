#ifndef PAYRANK_H
#define PAYRANK_H

#include <QDate>
#include <QMainWindow>
#include <QTime>

#include "cardsql.h"
#include "rfid.h"

namespace Ui {
class PayRank;
}

class PayRank : public QMainWindow {
    Q_OBJECT

public:
    explicit PayRank(QWidget* parent = nullptr);
    ~PayRank();
    int findUse();

private slots:
    void on_prevBt_clicked();

    void readCard(); // 读卡

    void on_readCardBt_clicked();

    void on_insigniaFindBt_clicked();

    void on_delUse_clicked();

    void on_update_insigniaBt_clicked();

    void on_update_phoneBt_clicked();

    void on_rechargeBt_clicked();

    void on_reissue_cardBt_clicked();

private:
    QTimer* qtime;
    RFID* rf;
    int fd;
    QString id;

private:
    Ui::PayRank* ui;
};

#endif // PAYRANK_H

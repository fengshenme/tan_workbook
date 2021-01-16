#ifndef HANDLECARD_H
#define HANDLECARD_H

#include <QDebug>
#include <QMainWindow>

#include "cardsql.h"
#include "rfid.h"

namespace Ui {
class HandleCard;
}

class HandleCard : public QMainWindow {
    Q_OBJECT

public:
    explicit HandleCard(QWidget* parent = nullptr);
    ~HandleCard();

private slots:
    void readCard(); // 读卡
    void on_entryCardNumBt_clicked();
    void on_prevBt_clicked();

    void on_readCardBt_clicked();

private:
    Ui::HandleCard* ui;
    QTimer* qtime;
    RFID* rf;
    int fd;
    CardSql* csl;
};

#endif // HANDLECARD_H

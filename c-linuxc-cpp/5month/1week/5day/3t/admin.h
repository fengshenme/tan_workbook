#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

#include "allpark.h"
#include "handlecard.h"
#include "payrank.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow {
    Q_OBJECT

public:
    explicit Admin(QWidget* parent = nullptr);
    ~Admin();

private slots:

    void on_handle_card_bt_clicked(); // 办卡

    void on_prev_win_clicked();

    void on_updateUse_clicked();

    void on_findAllBt_clicked();

private:
    Ui::Admin* ui;
};

#endif // ADMIN_H

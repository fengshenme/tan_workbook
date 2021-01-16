#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_handle_card_bt_clicked()
{
    HandleCard* hcd = new HandleCard(this);
    hcd->show();

    this->hide();
}

void Admin::on_prev_win_clicked()
{
    this->parentWidget()->show();
    this->close();
}

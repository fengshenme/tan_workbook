#include "conlamp.h"
#include "ui_conlamp.h"

ConLamp::ConLamp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConLamp)
{
    ui->setupUi(this);
    flag_lamp = false;
}

ConLamp::~ConLamp()
{
    delete ui;
}

void ConLamp::on_pushButton_clicked()
{
    this->parentWidget()->show();

    this->close();
}

void ConLamp::on_switchON_clicked()
{
    flag_lamp = !flag_lamp;
    if(flag_lamp)
    {
    ui->switchON->setStyleSheet("background-color: rgb(255, 0, 0);border-radius:40px; "); // 设置为红色,圆
    ui->switchON->setText("开");
    }
    else
    {
        ui->switchON->setStyleSheet("background-color: rgb(123, 123, 123);border-radius:40px; "); // 设置为灰色,圆
        ui->switchON->setText("关");
    }

}

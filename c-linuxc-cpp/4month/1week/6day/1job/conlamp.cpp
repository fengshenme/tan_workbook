#include "conlamp.h"
#include "ui_conlamp.h"
#include <QColorDialog>
#include <QDebug>

ConLamp::ConLamp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConLamp)
{
    ui->setupUi(this);
    flag_lamp = false;
    lamp_color = "background-color: rgb(255, 255, 255);";
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
        ui->lampBu->setStyleSheet(lamp_color.append("border-radius:200px;"));
        ui->lampBu->setText("亮");

    }
    else
    {
        ui->switchON->setStyleSheet("background-color: rgb(217, 217, 217);border-radius:40px; "); // 设置为灰色,圆
        ui->switchON->setText("关");
        ui->lampBu->setStyleSheet("background-color: rgb(217, 217, 217);border-radius:200px;");
         ui->lampBu->setText("熄");
    }

}

void ConLamp::on_lampBu_clicked()
{
    QColor ret = QColorDialog::getColor(Qt::red, this, "选择颜色1");

    if(ret.isValid())
    {
//        qDebug("%x", ret.rgb()) ;
//        qDebug() << ret.red() << ret.green() << ret.blue();

        lamp_color.clear();
        lamp_color = QString("background-color: rgb(%1, %2, %3);").arg(ret.red()).arg(ret.green()).arg(ret.blue());

    }
    else // 颜色值非法,取消
    {
         qDebug()<<"点击了取消";
    }

}

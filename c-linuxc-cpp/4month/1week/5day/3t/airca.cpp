#include "airca.h"
#include "ui_airca.h"

Airca::Airca(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Airca)
{
    ui->setupUi(this);
}

Airca::~Airca()
{
    delete ui;
}

void Airca::on_pushButton_clicked()
{
    //得到上一级窗口，并显示
    this->parentWidget()->show();
    //当前主窗口关闭
    delete this;
}

void Airca::on_pushButton_2_clicked()
{
    //得到登录窗口，并显示
    this->parentWidget()->parentWidget()->show();
    //当前主窗口关闭
    delete this;
}

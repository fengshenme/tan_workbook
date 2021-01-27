#include "airwin.h"
#include "ui_airwin.h"

AirWin::AirWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AirWin)
{
    ui->setupUi(this);
}

AirWin::~AirWin()
{
    delete ui;
}

void AirWin::on_spinBox_valueChanged(int arg)
{
    ui->lcdNumber->display(arg);
}

void AirWin::on_retpb_clicked()
{
    this->parentWidget()->show();

//    this->close();

    delete this;
}

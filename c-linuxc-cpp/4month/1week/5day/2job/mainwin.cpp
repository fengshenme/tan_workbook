#include "mainwin.h"
#include "ui_mainwin.h"
#include "airwin.h"
#include "conlamp.h"

#include <QDebug>

MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);
}

MainWin::~MainWin()
{
    delete ui;
}

void MainWin::on_retbt_clicked()
{
    this->parentWidget()->show();

    this->close();
}

void MainWin::funca(QString str1, QString str2)
{

    qDebug() << str1 << ":" << str2;
    QString tt = "欢迎:";
    tt += str1;
    tt.append("用户");
    ui->label_2->setText(tt);

}



void MainWin::on_airWin_clicked()
{
    AirWin *newW = new AirWin(this);
    newW->show();

    this->hide();

}

void MainWin::on_conLampWin_clicked()
{
     ConLamp *newcol= new ConLamp(this);

     newcol->show();

     this->hide();

}

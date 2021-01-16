#include "loginwin.h"
#include "ui_loginwin.h"
#include "mainwin.h"

#include <QDebug>

LoginWin::LoginWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWin)
{
    ui->setupUi(this);

    count = 0;
    this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/img/27.jpg);}");

}

LoginWin::~LoginWin()
{
    delete ui;
}


void LoginWin::on_loginG_clicked()
{
    QString name = ui->usele->text();
    QString passw = ui->passwle->text();

    qDebug() << name  << ":" << passw;

    if(name == "abc" || passw == "123")
    {
        //        qDebug() << "login success" ;

            MainWin *newwin =  new MainWin(this);

            //通过信号传递参数
            connect(this,SIGNAL(mysignal(QString, QString)), newwin, SLOT(funca(QString, QString)));
            emit mysignal(name, passw);

            newwin->show();

            this->hide();

    }
    else
    {
        count ++;
        if(count >= 3)
        {
            count = 0;

            ui->usele->setEnabled(false);
            ui->passwle->setEnabled(false);
        }
    }

}

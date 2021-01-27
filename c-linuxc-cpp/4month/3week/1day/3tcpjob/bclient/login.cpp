
#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QDebug>

Login::Login(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Login)
{
    ui->setupUi(this);

    count = 3;
    this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/img/27.jpg);}");

}

Login::~Login()
{
    delete ui;
}


void Login::on_loginG_clicked()
{
    QString name = ui->usele->text();
    QString passw = ui->passwle->text();

    qDebug() << name  << ":" << passw;

    if(name == "abc" && passw == "123")
    {
        // qDebug() << "login success" ;

        MainWindow *newwin =  new MainWindow(this);

        //通过信号传递参数
        connect(this,SIGNAL(mysignal(QString, QString)), newwin, SLOT(funca(QString, QString)));
        emit mysignal(name, passw);

        newwin->show();

        this->hide();

    }
    else
    {
        count --;

        QString text = QString("账号密码错误 ,还可以尝试 %1 次").arg(count);
        QMessageBox::StandardButton ifl = QMessageBox::information(this, "登录提示", text, QMessageBox::Ok | QMessageBox::Cancel);
        if(ifl == QMessageBox::Ok)
        {
            qDebug() << "success";
            QMessageBox::critical(this,"提示", "选择再来");
        }
        else if(ifl == QMessageBox::Cancel)
        {

            qDebug() << "Cancel";
            QMessageBox::critical(this,"提示", "选择取消");
        }


        if(count <= 0)
        {
            count = 3;

            ui->usele->setEnabled(false);
            ui->passwle->setEnabled(false);
            ui->loginG->setEnabled(false);
        }

    }

}

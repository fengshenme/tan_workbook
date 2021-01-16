#include "loginwin.h"
#include "ui_loginwin.h"
#include "mainwindow.h"
#include "registerwin.h"

LoginWin::LoginWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWin)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("./test.db");
    if(db.open())
    {
        qDebug() << "打开成功";
    }
    QSqlQuery qsq = QSqlQuery(db);

    bool ret = qsq.exec("create table if not exists tb_goods(id char(10) primary key not null,pruduct text not null, number int, price float);");

    if(!ret)
    {
        qDebug() << "商品表创建失败!" << qsq.lastError().text();
    }
    ret = qsq.exec("create table if not exists tb_admin(id char(10) primary key not null,usera text not null, passw char(20));");

    if(!ret)
    {
        qDebug() << "管理员表创建失败!" << qsq.lastError().text();
    }

}

LoginWin::~LoginWin()
{
    db.close();
    delete ui;
}

void LoginWin::on_loginbt_clicked()
{

    QString name = ui->accoutle->text();
    QString pass = ui->passle->text();
    QString cmd = QString("select * from tb_admin where usera='%1' and passw='%2' ;").arg(name).arg(pass);
    QSqlQuery qsq = QSqlQuery(db);
    if(!qsq.exec(cmd))
    {
        qDebug() << "查找失败:" << qsq.lastError().text();
        QMessageBox::critical(this,"提示", "查找失败");
    }

    if(qsq.next())
    {

        qDebug() << qsq.value(0).toString();
        MainWindow *mwi = new MainWindow(this);

        mwi->setQSqlDatabase(db);
        mwi->show();
        this->hide();
    }
    else
    {
        QMessageBox::critical(this,"提示", "登录失败");
    }



    return;
}

void LoginWin::on_registerBt_clicked()
{
    RegisterWin *qwn = new RegisterWin(this);

    qwn->setQSqlDatabase(db);
    qwn->show();

    this->hide();

    return ;

}

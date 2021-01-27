
#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Login)
{
    ui->setupUi(this);

    count = 3;
    this->setStyleSheet("Login{background-image: url(:/new/prefix1/img/27.jpg);}");

    cli = new QTcpSocket();
    //
    if(cli->bind(QHostAddress::Any, 8181))
    {
        qDebug() << "bind success...";
    }

    // 连接服务器
    // cli->connectToHost(QHostAddress("192.168.19.80"), 6869);
    cli->connectToHost(QHostAddress("127.0.0.1"), 6869);

    stra = QString("127.0.0.1:6869:");
    // stra = QString("%1%2%3").arg("192.168.19.80").arg(":").arg("6869:");

    connect(cli, SIGNAL(readyRead()), this, SLOT(mainroute()));

}

Login::~Login()
{
    delete ui;
}

void Login::log_check(bool flag)
{
    if(flag)
    {
        // qDebug() << "login success" ;

        MainWindow *newwin =  new MainWindow(this, cli);

        //登录成功到主界面
        connect(this,SIGNAL(messma(QByteArray)), newwin, SLOT(func2(QByteArray)));

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
        }
        else if(ifl == QMessageBox::Cancel)
        {
            qDebug() << "Cancel";
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


void Login::mainroute()
{
    QByteArray bty =  cli->readAll();
    QString aa = QString(bty);

    QString stprex = aa.section(':', 0, 1);
    qDebug() << stprex;
    qDebug() << aa;


    if(stprex == "m:login")
    {
        log_check(aa.section(':', 2, 2) == "true");
    }
    else
    {
        emit messma(bty);
    }

    qDebug() << aa << "接收字节数:" << bty.size();
}

void Login::on_loginG_clicked()
{
    QString name = ui->usele->text();
    QString passw = ui->passwle->text();


    QString tmp = QString("m:login:%1:%2").arg(name).arg(passw);
    qDebug() << tmp;
    cli->write(tmp.toUtf8());

}

void Login::on_registB_clicked()
{


    RegWin *reg = new RegWin(this);


    reg->show();


}

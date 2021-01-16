
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

    connect(cli, SIGNAL(readyRead()), this, SLOT(func2()));

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
//            QMessageBox::critical(this,"提示", "选择再来");
        }
        else if(ifl == QMessageBox::Cancel)
        {

            qDebug() << "Cancel";
//            QMessageBox::critical(this,"提示", "选择取消");
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

void Login::on_registB_clicked()
{


    RegWin *reg = new RegWin(this);


    reg->show();


}

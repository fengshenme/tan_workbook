
#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Login)
{
    ui->setupUi(this);

    setWindowTitle("IQ聊天");

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

    QString str = load_status();
    if(str.section(":", 1, 1) == "auto")
    {
        QString tmp = QString("m:login:%1").arg(str.section(":", 2));
        qDebug() << tmp;
        cli->write(tmp.toUtf8());
    }
    else if(str.section(":", 1, 1) == "passw")
    {
        aupass = str.section(":", 2);
    }


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

        bool pabl = ui->keep_passw->isChecked();
        bool aubl =  ui->auto_login->isChecked();
        if(pabl && aubl)
        {
            //设置自动登录
            usestat.replace("login", "auto");
        }
        else if(aubl)
        {
            //设置自动登录
            usestat.replace("login", "auto");
        }
        else if(pabl)
        {
            // 密码保存
            usestat.replace("login", "passw");
        }

        if(pabl || aubl)
        {
            save_status(usestat);
        }
        else
        {
            save_status("0");
        }

        newwin->show();
        ui->passwle->clear();
        ui->usele->clear();
        ui->auto_login->setChecked(false);
        ui->keep_passw->setChecked(false);
        this->hide();

    }
    else
    {
        count--;

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

QString Login::load_status()
{
    QFile file("H:/git-repo/qtdata/state.txt");

    bool ret = file.open(QIODevice::ReadOnly );

    if(!ret)
    {
        qDebug() << "打开文件失败";
        file.close();
        return "0";
    }
    QString str =  QString(file.readAll());
    qDebug() << str;
    file.close();

    return str;

}

bool Login::save_status(QString strstat)
{

    QFile file("H:/git-repo/qtdata/state.txt");

    bool ret = file.open(QIODevice::WriteOnly);
    qDebug() << strstat;

    if(!ret)
    {
        qDebug() << "打开文件失败";
        file.close();
        return false;
    }
    qDebug() << file.write(strstat.toUtf8());
    file.close();

    return true;

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
    else if(stprex == "m:register")
    {
        emit regist(bty);
    }
    else if(stprex == "m:repass")
    {
        emit repas(bty);
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


     usestat = QString("m:login:%1:%2").arg(name).arg(passw);
    qDebug() << usestat;
    cli->write(usestat.toUtf8());

}

void Login::on_registB_clicked()
{

    RegWin *reg = new RegWin(this, cli);

    connect(this,SIGNAL(regist(QByteArray)), reg, SLOT(feedback(QByteArray)));
    reg->show();
//    this->hide();


}

void Login::on_pushButton_clicked()
{

    RePassWin *rpw = new RePassWin(this, cli);


    connect(this,SIGNAL(repas(QByteArray)), rpw, SLOT(rep_feed_back(QByteArray)));
    rpw->show();
//    this->hide();


}


void Login::on_usele_textEdited(const QString &arg1)
{
    qDebug() << arg1;
    if(aupass.section(":", 0, 0) == arg1)
    {
        ui->passwle->setText(aupass.section(":", 1, 1));
        ui->keep_passw->setChecked(true);
    }
}

void Login::on_usele_editingFinished()
{
    QString name = ui->usele->text();


    name = QString("m:heport:%1").arg(name);
    qDebug() << name;

    cli->write(name.toUtf8());

}

#include "registerwin.h"
#include "ui_registerwin.h"

RegisterWin::RegisterWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWin)
{
    ui->setupUi(this);
}

RegisterWin::~RegisterWin()
{
    delete ui;
}

void RegisterWin::setQSqlDatabase(QSqlDatabase d)
{
    db = d;
}

void RegisterWin::closeEvent(QCloseEvent *)
{
    this->parentWidget()->show();
}

void RegisterWin::on_registerBt_clicked()
{
    QString id = QString("%1").arg(time(0))  ;

    if(ui->passLe->text() != ui->passLe2->text())
     {
        QMessageBox::critical(this,"提示", "两次密码不一致");
        return ;
    }

    qDebug() << id;
    //字符串拼接得到完整的插入语句
    QString cmd = QString("insert into tb_admin values(%1, \"%2\", \"%3\");")
                      .arg(id).arg(ui->accountLe->text())
                      .arg(ui->passLe->text());

    cmd.replace('\n', "");
    QSqlQuery qsq = QSqlQuery(db);
    if(!qsq.exec(cmd))
    {
        qDebug() << "增加失败" << qsq.lastError().text();
        QMessageBox::critical(this,"提示", "注册失败");
    }
    else
    {
        QMessageBox::information(this,"提示", "注册成功");
    }
    ui->accountLe->clear();
    ui->passLe->clear();
    ui->passLe2->clear();

}

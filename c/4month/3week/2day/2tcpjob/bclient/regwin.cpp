#include "regwin.h"
#include "ui_regwin.h"

RegWin::RegWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegWin)
{
    ui->setupUi(this);

    setWindowTitle("注册窗口");


    ind = 0;

    lis.append("您最喜欢的一本书是什么?");
    lis.append("您最喜欢的小学老师是谁?");
    lis.append("您的兴趣爱好是什么?");
    lis.append("您的手机号是多少?");
    lis.append("您最喜欢的明星是谁?");

    int i;
    for ( i = 0; i < lis.size(); ++i)
        ui->comboBox->addItem(lis[i]);

}

RegWin::~RegWin()
{
    delete ui;
}


void RegWin::on_registerbt_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString enanle = ui->enanle->text();

    //  用户数据保存格式 1: 用户名 2:密码 3:密保问题代号 4:密保问题答案
    QString use = QString("%1:%2:%3:%4:").arg(username).arg(password).arg(ind).arg(enanle);
    use.replace("\n", "");
    use.append("\n");


    QFile file("H:/git-repo/qtdata/use.txt");

    bool ret = file.open(QIODevice::WriteOnly | QIODevice::Append);

    if(!ret)
    {
        qDebug() << "打开文件失败";
        QMessageBox::critical(this,"提示", "注册失败");
    }

    if(file.write(use.toUtf8()) > 0)
    {
        QMessageBox::information(this,"提示", "注册成功,请登录");
        this->close();
    }
    else
    {
         QMessageBox::critical(this,"提示", "注册失败");
         ui->username->clear();
         ui->password->clear();
         ui->enanle->clear();
    }

    file.close();


}

void RegWin::on_comboBox_activated(int index)
{
    ind = index;
}

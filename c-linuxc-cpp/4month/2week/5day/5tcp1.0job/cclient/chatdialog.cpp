#include "chatdialog.h"



ChatDialog::ChatDialog(QWidget *parent, QString ipa, QTcpSocket *cli): QDialog(parent)
{
    this->stra = ipa;
    this->cli = cli;
    this->setWindowTitle("聊天框");
    this->resize(590, 399);

    chatlistwid = new QListWidget(this);
    chatlistwid->setGeometry(3, 5, 581, 310);
    chatlistwid->setStyleSheet("border-radius:20px; background-color: rgb(220, 220, 220); border:1px solid#BFBFBF;");

    chatte = new QTextEdit(this);
    chatte->setGeometry(3, 320,  461, 70);
    chatte->setStyleSheet("border-radius:10px;border:1px solid#BFBFBF; background-color: rgb(222, 222, 222);");

    sendmess = new QPushButton(this);
    sendmess->setGeometry(470, 320, 111, 36);
    sendmess->setText("发送");
    sendmess->setStyleSheet("background-color: rgb(85, 170, 255); border-radius: 18px;");

    sendexpr = new QPushButton(this);
    sendexpr->setGeometry(470, 357, 111, 36);
    sendexpr->setText("发送表情");
    sendexpr->setStyleSheet("background-color: rgb(85, 170, 255); border-radius: 18px;");

    //关联信号与槽函数
    connect(sendmess, &QPushButton::clicked, this, &ChatDialog::on_sendmess_clicked);
    connect(sendexpr, SIGNAL(clicked()), this, SLOT(on_sendexpr_clicked()));




}

ChatDialog::ChatDialog(QWidget *parent): QDialog(parent)
{

}

ChatDialog::~ChatDialog()
{
    qDebug() << "dialog----free" ;
//    emit windelsignal();

}

void ChatDialog::on_sendmess_clicked()
{
    QString str =  this->chatte->toPlainText();
    QString tmp = stra  + ":" + str;
    qDebug() << "成功发送字节数:" << cli->write(tmp.toUtf8());
    chatte->clear();
}

void ChatDialog::to_msg(QString msg)
{
    QString sta = msg.section(":", 0, 1);
    qDebug() << sta;
    if(sta == stra)
    {
        chatlistwid->addItem(msg);
    }
}

void ChatDialog::on_sendexpr_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "选择文件","H:/sharecode/", "*.jpg");

    QFile file(fileName);

    bool ret = file.open(QIODevice::ReadOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
    }
    QByteArray qarr =  file.readAll();


    QByteArray byar = QString("f" + stra).toUtf8();

    byar.append(qarr);
    cli->write(qarr, qarr.size());
    file.close();

    qDebug() << fileName;
}



void ChatDialog::closeEvent(QCloseEvent *event)
{
        //|窗口关闭之前需要的操作~
}

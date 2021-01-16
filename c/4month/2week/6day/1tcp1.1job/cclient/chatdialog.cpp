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
    QString tmp = "m:" + stra  + ":" + str; // 第一个字符代表上传的是什么类型数据, 第二段字符是ip和端口识别, 第三段是正文
    qDebug() << "成功发送字节数:" << cli->write(tmp.toUtf8());
    chatte->clear();
}

void ChatDialog::to_msg(QByteArray msg)
{

    QString msga = QString(msg);

    QString sta = msga.section(":", 1, 2);

    QString tmp;

    qDebug() << sta;
    if(sta == stra)
    {

        if(msga.section(':', 0, 0) == "f")
        {
            QString fn = msga.section(":", 3, 3);

            QByteArray byar = msg.mid(msga.section(':', 0, 3).toUtf8().size()+1);

            QFile file("H:/sharecode/rep/" + fn);

            bool ret = file.open(QIODevice::WriteOnly);

            if(!ret)
            {
                qDebug() << "打开文件失败";
            }

            qDebug() << "文件大小:" << byar.size();

            file.write(byar);

            file.close();
            qDebug() << "文件save success";
            qDebug() << fn;

        }
        else if(msga.section(':', 0, 0) == "m")
        {
            chatlistwid->addItem(msg);
        }

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

    QStringList list1 = fileName.split('/');
    qDebug() << list1[list1.size()-1];
    // 第一段字符代表上传的文件, 第二段字符是ip和端口识别, 第三段是是文件名及后缀, 第四段是数据
    QByteArray byar = QString("f:" + stra + ":" + list1[list1.size()-1] + ":").toUtf8();

    byar.append(qarr);
    cli->write(byar, byar.size());
    file.close();
    //    上传文件大小
    qDebug() << "文件大小:" << qarr.size();
    qDebug() << byar.size();
    qDebug() << fileName;
}



void ChatDialog::closeEvent(QCloseEvent *event)
{
    //|窗口关闭之前需要的操作~
}

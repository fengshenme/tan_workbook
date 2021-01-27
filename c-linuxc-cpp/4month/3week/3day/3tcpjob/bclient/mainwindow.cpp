#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QTcpSocket *cl)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("8181");

    this->cli = cl;

}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::func2(QByteArray msg)
{
    QByteArray bty =  msg;
    QString aa = QString(bty);

    QString stprex = aa.section(':', 0, 0);
    qDebug() << stprex;
    if(stprex == "getlist")
    {
        ui->listWidget->clear();
        QStringList  stelist = aa.section(':', 1).split("\n");
        int i;
        for(i = 0; i < stelist.size(); i++)
        {
           ui->listWidget->addItem( stelist.at(i));
        }
    }

    emit messgo(bty);

    qDebug() << aa << "接收字节数:" << bty.size();
}



void MainWindow::on_refuse_clicked()
{
    QString tmp = "m:getlist";
    qDebug() << "成功发送字节数:" << cli->write(tmp.toUtf8());
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
       stra = item->text() + ":";

       ui->label_2->setText(QString("选择与%1聊天").arg(stra));

       ChatDialog *mal = new ChatDialog(this , item->text(), cli);

       connect(this, &MainWindow::messgo, mal, &ChatDialog::to_msg);

       mal->setAttribute(Qt::WA_DeleteOnClose);
       mal->show();

}



void MainWindow::on_logout_clicked()
{

    QFile file("H:/git-repo/qtdata/state.txt");

    bool ret = file.open(QIODevice::WriteOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
        file.close();
    }
    QString strstat = "0";
    qDebug() << file.write(strstat.toUtf8());
    file.close();
    this->parentWidget()->show();
    this->close();

}

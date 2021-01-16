#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    com.clear();
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_17, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_18, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_19, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_6, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(com_func()));
    connect(ui->pushButton_11, SIGNAL(clicked(bool)), this, SLOT(com_func()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::com_func()
{
    //获取信号的发送者
    QPushButton *p=qobject_cast<QPushButton *>(sender());

    qDebug() << p->text();

    com.append(p->text());

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);

}

void MainWindow::on_pushButton_13_clicked()
{
    QChar add = '+';
    com.append(",");
    com.append(add);
    com.append(",");

    QString tmp = com;

    tmp.replace(",", "");

    qDebug() << tmp;

    ui->textBrowser->setText(tmp);

}

void MainWindow::on_pushButton_20_clicked()
{

    com.append(",-,");

    QString tmp = com;

    tmp.replace(",", "");

    qDebug() << tmp;

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_14_clicked()
{
    com.append(",*,");

    QString tmp = com;

    tmp.replace(",", "");

    qDebug() << tmp;

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_16_clicked()
{
    com.append(",/,");

    QString tmp = com;

    tmp.replace(",", "");

    qDebug() << tmp;

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_12_clicked()
{



    QString tmp = com;

    QStringList lis = tmp.split(",");


    int atmp = lis[1].at(0).unicode();
    double sum = 0;
    bool ok;
    switch (atmp) {
    case '+':
        sum = lis[0].toDouble(&ok) + lis[2].toDouble(&ok);
        ui->textBrowser->setText(QString::number(sum));
        break;
    case '-':
        sum = lis[0].toDouble(&ok) - lis[2].toDouble(&ok);
        ui->textBrowser->setText(QString::number(sum));
        break;
    case '*':
        sum = lis[0].toDouble(&ok) * lis[2].toDouble(&ok);
        ui->textBrowser->setText(QString::number(sum));
        break;
    case '/':
        sum = lis[0].toDouble(&ok) / lis[2].toDouble(&ok);
        ui->textBrowser->setText(QString::number(sum));
        break;

    default:
        break;
    }

    com = QString::number(sum);
    qDebug() << lis[0].toInt(&ok, 10);
    qDebug() << lis[2].toInt(&ok, 10);
    qDebug() << atmp;
    qDebug() << sum;
    qDebug() << tmp;
    qDebug() << lis[0] << lis[1] << lis[2];
}



void MainWindow::on_pushButton_10_clicked()
{
    com.clear();
    ui->textBrowser->setText(com);
}




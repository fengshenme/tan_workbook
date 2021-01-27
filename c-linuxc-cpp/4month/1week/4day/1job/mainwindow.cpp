#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    com = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int c1 = 1;

    com.append(QString::number(c1));

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


void MainWindow::on_pushButton_2_clicked()
{
    int c1 = 2;

    com.append(QString::number(c1));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_3_clicked()
{

    com.append(QString::number(3));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_17_clicked()
{
    com.append(QString::number(4));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_18_clicked()
{
    com.append(QString::number(5));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_19_clicked()
{
    com.append(QString::number(6));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_4_clicked()
{
    com.append(QString::number(7));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_6_clicked()
{
    com.append(QString::number(8));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_5_clicked()
{
    com.append(QString::number(9));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_11_clicked()
{
    com.append(QString::number(0));

    QString tmp = com;

    tmp.replace(",", "");

    ui->textBrowser->setText(tmp);
}

void MainWindow::on_pushButton_10_clicked()
{
    com.clear();
    ui->textBrowser->setText(com);
}




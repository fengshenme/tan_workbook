#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;
    lflags = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::asfunc(QString, int)
{
    // 自定义槽函数
}

void MainWindow::on_radioButton_2_clicked()
{
    QString co = QString("QMainWindow{background-image: url(:/new/prefix1/img/16.jpg);}");
    this->setStyleSheet(co);
}

void MainWindow::on_radioButton_clicked()
{
    QString co = QString("QMainWindow{background-image: url(:/new/prefix1/img/23.jpg);}");
    this->setStyleSheet(co);
}

void MainWindow::on_lineEdit_editingFinished()
{

    QString bcle = ui->lineEdit->text();

    //    bcle == "abc"

    qDebug() << bcle ;

}


void MainWindow::on_lineEdit_returnPressed()
{

}

void MainWindow::on_lineEdit_selectionChanged()
{

}

void MainWindow::on_pushButton_clicked()
{
    QString usename =  ui->lineEdit->text();
    QString passwd  = ui->lineEdit_2->text();

    if(usename == "abc" || passwd == "123")
    {
        qDebug() << "login success" ;
    }
    else
    {
        count ++;
        if(count >= 3)
        {
            count = 0;

            ui->lineEdit->setEnabled(false);
            ui->lineEdit_2->setEnabled(false);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    lflags = !lflags;
    if(lflags)
    {

        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
    else
    {
         ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
}

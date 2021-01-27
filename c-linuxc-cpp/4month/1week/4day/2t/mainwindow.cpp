#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rc->setMaxLength(3);
    ui->gc->setMaxLength(3);
    ui->bc->setMaxLength(3);

    QValidator *vali = new QIntValidator(0, 255, this);
    ui->rc->setValidator(vali);
    ui->gc->setValidator(vali);
    ui->bc->setValidator(vali);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbu1_clicked()
{
    QString rcle = ui->rc->text();
    QString gcle = ui->gc->text();
    QString bcle = ui->bc->text();

    QString co = QString("QMainWindow{background-color: rgb(%1, %2, %3);}").arg(rcle).arg(gcle).arg(bcle);
    this->setStyleSheet(co);

    qDebug() << "账号名:" ;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << e->key();
    qDebug() << e->text();
    QChar a = e->text().at(0);
    printf("%d\n",  a.digitValue());
    return ;
}

void MainWindow::resizeEvent(QResizeEvent *)
{

    qsrand(time(NULL));
    int r =  qrand();
    int g =  qrand();
    int b =  qrand();

     r = r%255;
     g = g%255;
     b = b%255;

    this->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b));
}


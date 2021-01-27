#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    qDebug() << ui->checkBox->checkState();
    qDebug() << ui->checkBox->isChecked();
}

void MainWindow::on_lineEdit_selectionChanged()
{
    qDebug() << "fsadfads";
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    qDebug() << arg1 << ":" << arg2;
}

void MainWindow::on_lineEdit_returnPressed()
{
    qDebug() << "asds";
}

void MainWindow::on_lineEdit_editingFinished()
{
    qDebug() << "a";
}

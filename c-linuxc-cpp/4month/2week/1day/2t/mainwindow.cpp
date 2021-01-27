#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//        this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏

    ui->menubar->setStyleSheet("background-color: rgb(85, 255, 127);");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionopen_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, "选择文件","H:/sharecode/", "*.txt *.c *.cpp");

    QFile file(fileName);

    bool ret = file.open(QIODevice::ReadOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
    }
    QByteArray qarr =  file.readAll();

    ui->textEdit->setText(qarr);

    file.close();
}

void MainWindow::on_actionsave_triggered()
{
    QString str = ui->textEdit->toPlainText();
    QFile file(fileName);

    bool ret = file.open(QIODevice::WriteOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
    }

    file.write(str.toUtf8());

    file.close();
}


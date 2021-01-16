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


void MainWindow::on_btopenfile_clicked()
{
       fileName = QFileDialog::getOpenFileName(this, "选择文件","H:/sharecode/", "*.txt *.c *.cpp");

      QFile file(fileName);

      bool ret = file.open(QIODevice::ReadOnly);

      if(!ret)
      {
          qDebug() << "打开文件失败";
      }
     QByteArray qarr =  file.readAll();



     ui->textb->setText(qarr);
     ui->textEdit->setText(qarr);

     file.close();

      qDebug() << fileName;

       QStringList list1 = fileName.split('/');
      qDebug() << list1[list1.size()-1];

}

void MainWindow::on_pushButton_clicked()
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



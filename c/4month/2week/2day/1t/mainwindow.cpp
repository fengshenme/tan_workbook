#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   QMenuBar *mebar = new QMenuBar(this);

   mebar->setGeometry(0, 0, 200, 30);
   QMenu *qm = new QMenu("文件", mebar);
   QMenu *qmedit = new QMenu("编辑", mebar);
   mebar->addMenu(qm);
   QAction *qct = qm->addAction("open");

   connect(qct, SIGNAL(triggered()), this, SLOT(openfile()));

   mebar->addMenu(qmedit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openfile()
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


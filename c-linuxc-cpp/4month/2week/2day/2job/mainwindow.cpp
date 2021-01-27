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
    //弹出显示目录的文件对话框
    QString dirname = QFileDialog::getExistingDirectory(this, "选择文件", "H:/sharecode/");
    qDebug()<<"你打开的目录是: "<<dirname;
    d_path = dirname;
    MainWindow::recursion(dirname);
}

void MainWindow::recursion(QString dir_path)
{
    //定义QDir对象
    QDir mydir(dir_path);

    //遍历目录  while(readdir()!=NULL)
     QStringList mylist = mydir.entryList();  //不能递归
    for(int i=0; i < mylist.size(); i++)
    {
        QString name = mylist.at(i);
        //拼接得到绝对路径
        QString allpath = QString("%1/%2").arg(dir_path).arg(name);
        //判断一下目录中各个文件的类型，并打印大小
        QFileInfo myinfo(allpath);  //正确，使用绝对路径
        if(myinfo.isDir()) //目录
        {
            qDebug() << "目前我遍历的是个目录： " << allpath;
//            if(name != "." && name != "..")
//            {
//                MainWindow::recursion(allpath);
//            }
            QIcon icon1(":/new/prefix1/img/diricon.jpg");
            QListWidgetItem *item1 = new QListWidgetItem(icon1, name);

            ui->listWidget->addItem(item1);

        }
        else //普通文件
        {

            qDebug() << "目前我遍历的是个普通文件： " << allpath << "  大小是： " << myinfo.size();
            QIcon icon1(":/new/prefix1/img/txtedit.jpg");
            QListWidgetItem *item2 = new QListWidgetItem(icon1, name);
            ui->listWidget->addItem(item2);

        }
    }
    return ;
}


void MainWindow::on_savefile_clicked()
{
    QString str = ui->textEdit->toPlainText();
    QFile file(allpath);

    bool ret = file.open(QIODevice::WriteOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
    }

    file.write(str.toUtf8());

    file.close();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

    //拼接得到绝对路径
    allpath = QString("%1/%2").arg(d_path).arg(item->text());

    QFile file(allpath);

    bool ret = file.open(QIODevice::ReadOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
    }
    QByteArray qarr =  file.readAll();

    ui->textEdit->setText(qarr);

    file.close();

}




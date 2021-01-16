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
        //拼接得到绝对路径
        QString allpath = QString("%1/%2").arg(dir_path).arg(mylist.at(i));
        //判断一下目录中各个文件的类型，并打印大小
        QFileInfo myinfo(allpath);  //正确，使用绝对路径
        if(myinfo.isDir()) //目录
        {
            qDebug() << "目前我遍历的是个目录： " << allpath;
            if(mylist.at(i) != "." && mylist.at(i) != "..")
            {
                MainWindow::recursion(allpath);
            }

        }
        else //普通文件
        {
            qDebug()<<"目前我遍历的是个普通文件： "<< allpath <<"  大小是： "<< myinfo.size();

        }
    }
    return ;
}



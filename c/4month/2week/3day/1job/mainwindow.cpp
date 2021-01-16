#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new QProcess ;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::recursion(QString dir_path)
{
    ui->listWidget->clear();
    //定义QDir对象
    QDir mydir(dir_path);

    qDebug() << dir_path;
    mylist.clear(); //清空
    //遍历目录  while(readdir()!=NULL)
    mylist = mydir.entryList();
    int i;
    for( i=0; i < mylist.size(); i++)
    {
        QString name = mylist.at(i);
        //拼接得到绝对路径
        allpath = QString("%1/%2").arg(dir_path).arg(name);

        //        qDebug() << allpath ;
        //判断一下目录中各个文件的类型，并打印大小
        QFileInfo myinfo(allpath);  //正确，使用绝对路径
        if(myinfo.isDir()) //目录
        {
            QIcon icon1(":/new/prefix1/img/diricon.jpg");
            QListWidgetItem *item1 = new QListWidgetItem(icon1, name);

            ui->listWidget->addItem(item1);

        }
        else //普通文件
        {

            QIcon icon1(":/new/prefix1/img/txtedit.jpg");
            QListWidgetItem *item2 = new QListWidgetItem(icon1, name);
            ui->listWidget->addItem(item2);

        }
    }
    return ;
}




void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{


    //拼接得到绝对路径
    allpath = QString("%1/%2").arg(d_path).arg(item->text());

    QFileInfo myinfo(allpath);  //正确，使用绝对路径
    if(myinfo.isDir()) //目录
    {
        qDebug() << allpath;



        if(allpath.lastIndexOf("..") > -1)
        {
            int position = d_path.lastIndexOf("/");
            d_path.replace(position, d_path.size()-position, "");
            qDebug() << d_path;
            QString tpath = allpath.replace("/..", "");
            qDebug() << tpath;
            if(d_path.indexOf("/") != -1)
                MainWindow::recursion(d_path);
            else
            {
                d_path = tpath;
                MainWindow::recursion(tpath);
            }

            return ;
        }
        if(allpath.lastIndexOf(".") > -1)
        {
            MainWindow::recursion(d_path);
            return ;
        }
        d_path = allpath;
        MainWindow::recursion(allpath);

    }
    else //普通文件
    {

        //        open_file(allpath);


        palyerme(allpath);

    }

}

void MainWindow::palyerme(QString path)
{

    p->close();
    p->waitForFinished();

    QString pp;
    if(path.lastIndexOf("/.") != -1 && path.lastIndexOf("/..") != -1)
        return;
    pp = QString("H:/sharecode/yueqian/win-mplayer/mplayer.exe -slave -quiet -wid %1 %2").arg(ui->textEdit->winId()).arg(path);


    qDebug() << pp;

    p->start(pp);
}


void MainWindow::on_actionsave_triggered()
{
    //        save_file(allpath);
}

//菜单栏中文件 的打开目录功能
void MainWindow::on_actionopen_triggered()
{
    //弹出显示目录的文件对话框
    QString dirname = QFileDialog::getExistingDirectory(this, "选择文件", "H:/sharecode/");
    qDebug()<<"你打开的目录是: "<<dirname;
    d_path = dirname;

    MainWindow::recursion(dirname);
}



void MainWindow::open_file(QString apath)
{

    QFile file(apath);

    bool ret = file.open(QIODevice::ReadOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
    }
    QByteArray qarr =  file.readAll();

    ui->textEdit->setText(qarr);

    file.close();

}

void MainWindow::save_file(QString apath)
{
    QString str = ui->textEdit->toPlainText();
    QFile file(apath);

    bool ret = file.open(QIODevice::WriteOnly);

    if(!ret)
    {
        qDebug() << "打开文件失败";
    }

    file.write(str.toUtf8());

    file.close();
}



void MainWindow::on_next_clicked()
{

    QString tmpp = allpath;

    tmpp.remove(0, allpath.lastIndexOf("/")+1);
    qDebug() << tmpp;

    int i;
    QString name;
    for( i=0; i < mylist.size(); i++)
    {
        name = mylist.at(i);
        if(tmpp == name)
            break;
    }

    i = ++i > (mylist.size()-1) ? 0 : i;

    if(mylist.at(i) == ".")
        i = ++i < 0 ? mylist.size()-1 : i;

    if( mylist.at(i) == "..")
        i = ++i < 0 ? mylist.size()-1 : i;

    allpath = QString("%1/%2").arg(d_path).arg(mylist.at(i));
    qDebug()  << allpath;
    palyerme(allpath);

}

void MainWindow::on_prev_clicked()
{
    QString tmpp = allpath;

    tmpp.remove(0, allpath.lastIndexOf("/")+1);
    qDebug() << tmpp;

    int i;
    QString name;
    for( i = 0; i < mylist.size(); i++)
    {
        name = mylist.at(i);
        if(tmpp == name)
            break;
    }

    i = --i < 0 ? mylist.size()-1 : i;

    if( mylist.at(i) == "..")
        i = --i < 0 ? mylist.size()-1 : i;

    if(mylist.at(i) == ".")
        i = --i < 0 ? mylist.size()-1 : i;;



    allpath = QString("%1/%2").arg(d_path).arg(mylist.at(i));
    qDebug() << allpath;
    palyerme(allpath);


}

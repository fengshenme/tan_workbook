#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      db = QSqlDatabase::addDatabase("QSQLITE");

      db.setDatabaseName("H:\\sharecode\\yueqian\\4month\\4week\\2day\\test.db");
      if(db.open())
      {
          qDebug() << "打开成功";
      }
      db.exec("create table if not exists tb_goods(id char(5) primary key not null,pruduct text not null, number int, price float);");

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_addGoods_clicked()
{
    int id = time(0) % 100000;

    qDebug() << id;
    //字符串拼接得到完整的插入语句
    QString cmd = QString("insert into tb_goods values(%1, \"%2\", \"%3\", %4);")
                      .arg(id).arg(ui->lineEdit->text())
                      .arg(ui->lineEdit_2->text())
                        .arg(ui->lineEdit_3->text());
    cmd.replace('\n', "");
    QSqlQuery qs = db.exec(cmd);
}

void MainWindow::on_delGoods_clicked()
{
    QString cmd = QString("delete from tb_goods where pruduct='%s';");
    QSqlQuery qs = db.exec(cmd);
}

void MainWindow::on_updateGoods_clicked()
{
    QString cmd = QString("update tb_goods set price=32.1  where pruduct='aef';");
    QSqlQuery qs = db.exec(cmd);
}

void MainWindow::on_selectGoods_clicked()
{
    QString cmd = QString("select * from tb_goods where pruduct='%s';");
    QSqlQuery qs = db.exec(cmd);
}

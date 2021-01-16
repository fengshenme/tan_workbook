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
    db.close();
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    this->parentWidget()->show();
}

void MainWindow::on_addGoods_clicked()
{
    QString id = QString("%1").arg(time(0))  ;

    qDebug() << id;
    //字符串拼接得到完整的插入语句
    QString cmd = QString("insert into tb_goods values(%1, \"%2\", \"%3\", %4);")
                      .arg(id).arg(ui->lineEdit->text())
                      .arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text());

    cmd.replace('\n', "");
    QSqlQuery qsq = QSqlQuery(db);
    if(!qsq.exec(cmd))
    {
        qDebug() << "增加失败" << qsq.lastError().text();
        QMessageBox::critical(this,"提示", "增加失败");
    }
    else
    {
         QMessageBox::information(this,"商品添加提示", "增加成功");
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

}

void MainWindow::on_delGoods_clicked()
{

    QString cmd = QString("delete from tb_goods where pruduct='%1';").arg(ui->lineEdit_4->text());
    QSqlQuery qsq = QSqlQuery(db);
    if(!qsq.exec(cmd))
    {
        qDebug() << "删除失败" << qsq.lastError().text();
        QMessageBox::critical(this,"提示", "删除失败");
    }
    else
    {
        QMessageBox::information(this,"提示", "删除成功");
    }

}

void MainWindow::on_updateGoods_clicked()
{
    QString cmd = QString("update tb_goods set price=%1, number=%2  where pruduct='%3';")
                      .arg(ui->lineEdit_7->text()).arg(ui->lineEdit_6->text()).arg(ui->lineEdit_5->text());
    QSqlQuery qsq = QSqlQuery(db);
    if(!qsq.exec(cmd))
    {
        qDebug() << "更新失败" << qsq.lastError().text();
        QMessageBox::critical(this,"提示", "更新失败");
    }
    else
    {
        QMessageBox::information(this,"提示", "更新成功");
    }

}

void MainWindow::on_selectGoods_clicked()
{
    ui->tableWidget->clear();
    QString cmd = QString("select * from tb_goods ;");
    QSqlQuery qsq = QSqlQuery(db);
    if(!qsq.exec(cmd))
    {
        qDebug() << "查找失败:" << qsq.lastError().text();
        QMessageBox::critical(this,"提示", "查找失败");
    }

    qDebug() << qsq.size();
    ui->tableWidget->setColumnCount(4);
    //设置水平头--》表格中的字段名字
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"id"<<"商品"<<"数量"<<"价格");
    //设置行数
    ui->tableWidget->setRowCount(8);

    int i = 0;
    while (qsq.next()) {

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(qsq.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(qsq.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(qsq.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(qsq.value(3).toString()));
        i++;        ;
    }

}

void MainWindow::setQSqlDatabase(QSqlDatabase d)
{
    db = d;
}

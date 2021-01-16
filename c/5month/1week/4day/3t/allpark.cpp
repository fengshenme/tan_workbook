#include "allpark.h"
#include "ui_allpark.h"
#include <QHeaderView>

AllPark::AllPark(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::AllPark)
{
    ui->setupUi(this);

    //设置列数 3列
    ui->tableWidget->setColumnCount(5); //
    //    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "车牌"
                                                             << "卡号"
                                                             << "用户手机号"
                                                             << "卡上余额"
                                                             << "充值记录");

    //0- id,1-车牌 insignia, 2-卡号-card_num, 3-用户手机号 phone, 4-卡上余额 balance,5-逻辑删除 bflags,
    //6-充值记录 pay_rank, 7-消费记录purchase_log ,8-入库时间-begin_time, 9-出库时间-end_time,
    // 10-停车价格 stop_price,11-停车位置 parking_bay;
}

AllPark::~AllPark()
{
    delete ui;
}

void AllPark::on_findAll_clicked()
{

    CardSql* csl = new CardSql();
    QSqlQuery qsq;
    QString cmd = QString("select * from tb_card  ;");
    qDebug() << cmd;
    if (csl->findCard(cmd, qsq) == 0) {
        qDebug() << qsq.size();
        int rows = qsq.size() < 5 ? 5 : qsq.size();
        ui->tableWidget->setRowCount(rows);
        int row = 0;
        while (qsq.next()) {

            //车牌号
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(qsq.value(1).toString()));
            // 卡号
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(qsq.value(2).toString()));
            // 手机号
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(qsq.value(3).toString()));
            // 余额
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(qsq.value(4).toString()));
            // 充值记录
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(qsq.value(6).toString()));
            row++;
        }

        QMessageBox::information(this, "提示", "查询成功");
    } else {
        QMessageBox::critical(this, "提示", "查询失败");
    }

    delete csl;
}

void AllPark::on_prevBt_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void AllPark::on_findAll_pressed()
{
    qDebug() << "asda";
}

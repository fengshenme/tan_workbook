#include "cardsql.h"

CardSql::CardSql()
{

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("./test.db");
    if (db.open()) {
        qDebug() << "打开成功";
    }
    QSqlQuery qsq = QSqlQuery(db);
    // id,车牌 insignia, 卡号-card_num, 用户手机号 phone, 卡上余额 balance,逻辑删除 bflags, 充值记录 pay_rank, 消费记录purchase_log
    // 入库时间begin_time, 出库时间 end_time, 停车价格 stop_price,停车位置 parking_bay;
    bool ret = qsq.exec("create table if not exists tb_card(id char(12) primary key not null, insignia text not null"
                        ",  card_num text not null, phone text , balance float ,bflags int not null, pay_rank text, purchase_log text"
                        ", begin_time text, end_time text, stop_price float, parking_bay text);");

    if (!ret) {
        qDebug() << "表创建失败!" << qsq.lastError().text();
    }
}

CardSql::~CardSql()
{
}

int CardSql::addCard(QString cmd)
{

    //    QString cmd = QString("insert into tb_card values(%1, '%2', '%3', %4);")
    //                      .arg(id) //id
    //                      .arg(insignia) // 车牌号
    //                      .arg(cardNum) // 停车卡号
    //                      .arg("0") // 手机号
    //                      .arg(0) // 余额
    //                      .arg(1) // 1代表存在, 0代表已删除
    //                      .arg("0") // 刚开始没有充值记录
    //                      .arg("0") // 刚注册没有消费记录
    //                      .arg("0") // 刚添加没有入库时间
    //                      .arg("0") // 刚添加没有出库时间
    //                      .arg("0") // 没有停车单价
    //                      .arg("0"); // 没有消费没有停车位置

    cmd.replace('\n', "");
    QSqlQuery qsq = QSqlQuery(db);
    if (!qsq.exec(cmd)) {
        qDebug() << "增加失败" << qsq.lastError().text();
        //        QMessageBox::critical(this, "提示", "增加失败");
        return -1;
    }

    return 0;
}

int CardSql::delCard(QString cmd)
{
    //    QString cmd = QString("delete from tb_goods where pruduct='%1';").arg(ui->lineEdit_4->text());
    QSqlQuery qsq = QSqlQuery(db);
    if (!qsq.exec(cmd)) {
        qDebug() << "删除失败" << qsq.lastError().text();
        //        QMessageBox::critical(this, "提示", "删除失败");
        return -1;
    }
    return 0;
}

int CardSql::updateCard(QString cmd)
{
    //    QString cmd = QString("update tb_goods set price=%1, number=%2  where pruduct='%3';")
    //                      .arg(ui->lineEdit_7->text()).arg(ui->lineEdit_6->text()).arg(ui->lineEdit_5->text());
    QSqlQuery qsq = QSqlQuery(db);
    if (!qsq.exec(cmd)) {
        qDebug() << "更新失败" << qsq.lastError().text();
        //        QMessageBox::critical(this, "提示", "更新失败");
        return -1;
    }

    return 0;
}

int CardSql::findCard(QString cmd, QSqlQuery& qsqy)
{

    //    ui->tableWidget->clear();
    //    QString cmd = QString("select * from tb_goods ;");
    QSqlQuery qsq = QSqlQuery(db);

    bool ret = qsq.exec(cmd);

    qsqy = qsq;

    if (!ret) {
        qDebug() << "查找失败:" << qsq.lastError().text();
        //        QMessageBox::critical(this,"提示", "查找失败");
        return -1;
    }

    return 0;
}

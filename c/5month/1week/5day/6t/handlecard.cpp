#include "handlecard.h"
#include "ui_handlecard.h"

HandleCard::HandleCard(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::HandleCard)
{
    ui->setupUi(this);

    // 初始化定时器
    qtime = new QTimer(this);
    qtime->setInterval(500);

    // 退出时,定时器需要停止
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(readCard()));

    rf = new RFID();

    //打开串口文件
    fd = rf->open_serial();

    /*初始化串口*/
    rf->init_tty(fd);

    rf->timeout.tv_sec = 1;
    rf->timeout.tv_usec = 0;
}

HandleCard::~HandleCard()
{
    delete ui;
}

//确保AB命令发送成功，并且模块响应成功，所以在写成定时器的曹函数
void HandleCard::readCard()
{
    int ret;

    //发送A命令
    ret = rf->PiccRequest(fd);
    if (ret == -1) //若是请求超时退出，必须要关闭串口后，重新打开才能再次读取数据
    {
        usleep(500000);
        rf->close_serial(fd);

        //打开串口文件
        fd = rf->open_serial();
        /*初始化串口*/
        rf->init_tty(fd);
        rf->timeout.tv_sec = 1;
        rf->timeout.tv_usec = 0;
        return;
    } else //(ret == 0)
    {
        printf("ok!\n");
    }
    //发送B命令 和获取卡号
    ret = rf->PiccAnticoll(fd);

    //若获取的cardid为0，或获取id超时，则需重新发送'A'命令
    if (rf->cardid == 0 || ret == -1)
        return;
    else if (ret == 0) {
        printf("card ID = %#x\n", rf->cardid); //打印cardid号
        ui->cardNum->setText(QString("%1").arg(rf->cardid));
        //        usleep(500000);
        qtime->stop();
    }

    return;
}

void HandleCard::on_entryCardNumBt_clicked()
{
    QString insignia = ui->carLe->text(); // 车牌号
    QString cardNum = ui->cardNum->text(); // 停车卡号

    qDebug() << insignia << ":" << cardNum;

    csl = new CardSql();

    QString id = QString("%1").arg(time(0));

    //    cardNum = id;

    qDebug() << id;

    //字符串拼接得到完整的插入语句
    QString cmd = QString("insert into tb_card values('%1', '%2', '%3', '%4', %5, %6, '%7', '%8', '%9', '%10', %11, '%12');")
                      .arg(id) //id
                      .arg(insignia) // 车牌号
                      .arg(cardNum) // 停车卡号
                      .arg("0") // 手机号
                      .arg(0) // 余额
                      .arg(1) // 1代表存在, 0代表已删除
                      .arg("0") // 刚开始没有充值记录 保存60条数据
                      .arg("0") // 刚注册没有消费记录 保存60条数据
                      .arg("0") // 刚添加没有入库时间
                      .arg("0") // 刚添加没有出库时间
                      .arg(0) // 没有停车单价
                      .arg("0"); // 没有消费没有停车位置

    if (csl->addCard(cmd) == 0) {
        QMessageBox::information(this, "提示", "办卡成功");
    } else {
        QMessageBox::critical(this, "提示", "办卡失败");
    }
    delete csl;
}

void HandleCard::on_prevBt_clicked()
{
    rf->close_serial(fd);
    qtime->stop();
    this->parentWidget()->show();
    delete rf;
    this->close();
}

void HandleCard::on_readCardBt_clicked()
{

    qtime->start();
    ui->cardNum->setText("请放上停车卡");
}

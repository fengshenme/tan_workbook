#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("串口连接工具");
    chatlistwid = ui->read_listWidget;

    //获取当前系统可以使用的串口信息
    QList<QSerialPortInfo> lspi = QSerialPortInfo::availablePorts();

    foreach (QSerialPortInfo spi, lspi) {
        ui->portcbox->addItem(spi.portName());
    }

    // 获取波特率list
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::BaudRate>();
    for (int i = 0; i < metaEnum.keyCount(); i++) {
        ui->portcbox_2->addItem(QString(metaEnum.valueToKeys(metaEnum.value(i))));
    }
    // 数据位
    metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    for (int i = 0; i < metaEnum.keyCount(); i++) {
        ui->portcbox_3->addItem(QString("%1").arg(metaEnum.value(i)));
    }
    // 奇偶校验
    metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    for (int i = 0; i < metaEnum.keyCount(); i++) {
        ui->portcbox_4->addItem(QString(metaEnum.valueToKeys(metaEnum.value(i))));
    }
    // 停止位
    metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    for (int i = 0; i < metaEnum.keyCount(); i++) {
        ui->portcbox_5->addItem(QString(metaEnum.valueToKeys(metaEnum.value(i))));
    }

    if (lspi.size() > 0) {
        port_flag = false;
    } else {
        port_flag = true;
    }

    ui->close_button->setEnabled(false);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (port_flag) {
        QMessageBox::information(this, "提示", "没有可用串口");
        return;
    }

    sport = new QSerialPort(ui->portcbox->currentText());

    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::BaudRate>();
    QString arg1 = ui->portcbox_2->currentText();
    sport->setBaudRate((QSerialPort::BaudRate)metaEnum.keyToValue(arg1.toUtf8().data()));
    qDebug() << arg1;

    metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    arg1 = ui->portcbox_3->currentText();
    sport->setDataBits((QSerialPort::DataBits)arg1.toInt());
    qDebug() << arg1;

    metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    arg1 = ui->portcbox_4->currentText();
    sport->setParity((QSerialPort::Parity)metaEnum.keyToValue(arg1.toUtf8().data()));
    qDebug() << arg1;

    metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    arg1 = ui->portcbox_5->currentText();
    sport->setStopBits((QSerialPort::StopBits)metaEnum.keyToValue(arg1.toUtf8().data()));
    qDebug() << arg1;

    if (ui->radioButton_2->isChecked()) {
        qDebug() << "RTS/CTS";
        sport->setFlowControl(QSerialPort::HardwareControl);
    } else if (ui->radioButton->isChecked()) {
        qDebug() << "XON/XOFF";
        sport->setFlowControl(QSerialPort::SoftwareControl);
    } else {
        sport->setFlowControl(QSerialPort::NoFlowControl);
    }

    if (!sport->open(QIODevice::ReadWrite)) {
        qDebug() << "打开串口失败";
    }
    //    sport->write();

    connect(sport, SIGNAL(readyRead()), this, SLOT(serprint()));

    ui->close_button->setEnabled(true);
    ui->pushButton->setEnabled(false);

    // 初始化定时器
    qtime = new QTimer(this);
    qtime->setInterval(1000); // 1秒钟

    qtime->start();
    //    信号发送者 , 信号, 信号接收者 , 信号接收执行函数(槽函数)
    connect(qtime, SIGNAL(timeout()), this, SLOT(timeFunc()));
}

void MainWindow::serprint()
{

    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    //    qDebug() << date.toString("yyyy-MM-dd ") << time.toString("hh:mm:ss");

    // QString str = QString("%1").arg(time.toString("hh:mm:ss"));
    QString str = QString("%1").arg(time.toString("hh:mm:ss"));

    QString str2 = QString("%1").arg(date.toString("yyyy-MM-dd "));
    chatlistwid->addItem(str2 + str);

    QByteArray astr = sport->readAll();
    qDebug() << astr.length();
    QString stt = QString(astr);
    chatlistwid->addItem(stt);
    //    sport->clear();
}

void MainWindow::on_close_button_clicked()
{
    sport->close();
    delete sport;
    qtime->stop();
    delete qtime;

    ui->pushButton->setEnabled(true);
    ui->close_button->setEnabled(false);
}

void MainWindow::timeFunc()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    //    qDebug() << date.toString("yyyy-MM-dd ") << time.toString("hh:mm:ss");

    // QString str = QString("%1").arg(time.toString("hh:mm:ss"));
    QString str = QString("%1").arg(time.toString("hh:mm:ss:"));

    QString str2 = QString("%1").arg(date.toString("yyyy-MM-dd "));
    ui->lcdNumber->display(str2 + str);
}

void MainWindow::on_clear_button_clicked()
{
    ui->read_listWidget->clear();
}

void MainWindow::on_send_button_clicked()
{
    QString messa = ui->send_textEdit->toPlainText();

    qDebug() << messa;
    if (sport == nullptr)
        return;
    sport->write(messa.toUtf8());
}

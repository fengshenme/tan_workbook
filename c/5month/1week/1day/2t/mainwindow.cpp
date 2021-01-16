#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
        sport = new QSerialPort(lspi[0].portName());
        port_flag = false;
    } else {
        port_flag = true;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sport;
}

void MainWindow::on_portcbox_activated(const QString& arg1)
{
    if (port_flag) {
        QMessageBox::information(this, "提示", "没有可用串口");
        return;
    }

    qDebug() << arg1;

    delete sport;
    sport = new QSerialPort(arg1);
}

void MainWindow::on_portcbox_2_activated(const QString& arg1)
{
    if (port_flag) {
        QMessageBox::information(this, "提示", "没有可用串口");
        return;
    }

    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::BaudRate>();
    QSerialPort::BaudRate value = (QSerialPort::BaudRate)metaEnum.keyToValue(arg1.toUtf8().data());
    qDebug() << value;

    sport->setBaudRate(value);
}

void MainWindow::on_portcbox_3_activated(const QString& arg1)
{
    if (port_flag) {
        QMessageBox::information(this, "提示", "没有可用串口");
        return;
    }

//    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
//    QSerialPort::DataBits value = (QSerialPort::DataBits)metaEnum.keyToValue(arg1.toUtf8().data());
    QSerialPort::DataBits value = (QSerialPort::DataBits)arg1.toInt();
    qDebug() << value;

    sport->setDataBits(value);
}

void MainWindow::on_portcbox_4_activated(const QString& arg1)
{
    if (port_flag) {
        QMessageBox::information(this, "提示", "没有可用串口");
        return;
    }

    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    QSerialPort::Parity value = (QSerialPort::Parity)metaEnum.keyToValue(arg1.toUtf8().data());
    qDebug() << value;

    sport->setParity(value);
}

void MainWindow::on_portcbox_5_activated(const QString& arg1)
{
    if (port_flag) {
        QMessageBox::information(this, "提示", "没有可用串口");
        return;
    }

    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    QSerialPort::StopBits value = (QSerialPort::StopBits)metaEnum.keyToValue(arg1.toUtf8().data());
    qDebug() << value;

    sport->setStopBits(value);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取当前系统可以使用的串口信息
    QList<QSerialPortInfo> lspi = QSerialPortInfo::availablePorts();
    foreach(QSerialPortInfo spi, lspi)
    {
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
        ui->portcbox_3->addItem(QString(metaEnum.valueToKeys(metaEnum.value(i))));
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


}

MainWindow::~MainWindow()
{
    delete ui;
}


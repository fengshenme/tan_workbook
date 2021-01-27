#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置列数 3列
    ui->tableWidget->setColumnCount(3); //
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");

    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文

    int row;
    for (row = 0; row < 5; ++row) {
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem("亚瑟"));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem("男"));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem("22"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

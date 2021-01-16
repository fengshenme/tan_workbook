#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>

#include "chatthread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals: //声明信号
    void messgo(QByteArray msg);
    void windelsignal(); //不带参数，自定义信号

private slots:
    void on_pushButton_clicked();
    void func2();
    void delcat();


    void on_refuse_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_test_clicked();


private:
    Ui::MainWindow *ui;
    QTcpSocket *cli;
     QString stra;
     ChatThread *cth;
};
#endif // MAINWINDOW_H

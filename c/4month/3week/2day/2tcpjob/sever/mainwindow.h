#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <QIODevice>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QMap>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool load_data();

 private slots:
    void func(); // 新的连接信号时执行的槽函数
    void func2(); // 来数据信号时执行的槽函数
    void discont(); // 断开信号的槽函数

    void on_pushButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QTcpServer * serv;
    QTcpSocket *soc;

    QMap<QString, QString> usedb;

    QString  uselist;
    QMap<QString, QTcpSocket *> *map;
};
#endif // MAINWINDOW_H

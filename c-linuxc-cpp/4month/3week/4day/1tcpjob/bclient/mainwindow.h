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
#include <QTcpSocket>
#include <QTimer>
#include <QDate>

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, QTcpSocket *cl = NULL);
    ~MainWindow();

signals: //声明信号
    void messgo(QByteArray msg);
    void windelsignal(); //不带参数，自定义信号

private slots:
    void func2(QByteArray msg);

    void on_refuse_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_logout_clicked();

    void timeFunc();

    void weather(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    QTcpSocket *cli;
    QString stra;
    ChatThread *cth;
    QTimer *qtime;
    QNetworkAccessManager manager; // 请求天气用
};
#endif // MAINWINDOW_H
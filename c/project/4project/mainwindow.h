#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QHostAddress>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QTcpSocket>

#include <QDate>
#include <QTimer>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include <QSysInfo>

#include <stdlib.h>

#include "adminlogin.h"
#include "mycamera.h"
#include "parkbutton.h"
#include "rfid.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    int updateParkSum();
    int findParkingBay();

signals:
    void messgo(QString cid, bool parflag);

public slots:

    // 刷卡
    void on_swipingBt_clicked();
    // 更新车位数
    void updateSum(bool bl);

private slots:
    void timeFunc();
    void weather(QNetworkReply* reply);
    void getTime(QNetworkReply* reply);

    void on_adminloginbt_clicked();

    void on_prevbt_pressed();

    void on_prevbt_released();

    void on_nextpt_pressed();

    void on_nextpt_released();
    void on_nextpt_clicked();

    void on_prevbt_clicked();
    // 视频刷新
    void swipingPo();

    void readCard(); // 读卡

private:
    Ui::MainWindow* ui;
    QTimer* qtime; // 更新时间用
    QNetworkAccessManager manager; // 请求天气和时间用
    QNetworkAccessManager manager2; // 请求天气和时间用

    int parking_sum; //剩余车位数
    QList<ParkButton*> mblist;
    QMap<QString, QString> map; // key为卡号,value为停车位置

    int parkpos;

    MyCamera* mycam;
    QTimer* potoqtime; // 摄像用
    QTimer* cardqtime; // 读卡用

    RFID* rf;
    int fd;
};
#endif // MAINWINDOW_H

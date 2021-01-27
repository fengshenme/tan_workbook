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

private slots:
    void timeFunc();
    void weather(QNetworkReply* reply);
    void getTime(QNetworkReply* reply);

private:
    Ui::MainWindow* ui;
    QTimer* qtime;
    QNetworkAccessManager manager; // 请求天气和时间用
    QNetworkAccessManager manager2; // 请求天气和时间用
};
#endif // MAINWINDOW_H

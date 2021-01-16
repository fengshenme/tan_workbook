#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTcpSocket>
#include <QString>

#include "regwin.h"
#include "mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
    class Login;
}
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void log_check(bool flag);

signals:
    void messma(QByteArray msg); //去主界面的

private slots:
    void on_loginG_clicked();

    void on_registB_clicked();

    void mainroute();



private:
    Ui::Login *ui;
    int count;
    QTcpSocket *cli;
    QString stra;
};

#endif // LOGIN_H

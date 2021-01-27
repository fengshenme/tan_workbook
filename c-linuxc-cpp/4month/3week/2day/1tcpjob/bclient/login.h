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

private slots:
    void on_loginG_clicked();

    void on_registB_clicked();

signals:
    void mysignal(QString, QString);
    void messgo(QByteArray msg);

private:
    Ui::Login *ui;
    int count;
    QTcpSocket *cli;
    QString stra;
};

#endif // LOGIN_H

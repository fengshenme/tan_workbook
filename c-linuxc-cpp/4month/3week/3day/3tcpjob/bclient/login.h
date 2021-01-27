#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTcpSocket>
#include <QString>
#include <QPainter>
#include <QImage>
#include <QBitmap>

#include "regwin.h"
#include "mainwindow.h"
#include "repasswin.h"


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
    QString load_status();
    bool save_status(QString strstat);
    void show_head(QByteArray msg);
    QPixmap PixmapToRound(const QPixmap &src, int radius);

signals:
    void messma(QByteArray msg); //去主界面的
    void regist(QByteArray msg); //去注册界面
    void repas(QByteArray msg); //去密码找回界面


private slots:
    void on_loginG_clicked();

    void on_registB_clicked();

    void mainroute();

    void on_pushButton_clicked();

    void on_usele_textEdited(const QString &arg1);

    void on_usele_editingFinished();

private:
    Ui::Login *ui;
    int count;
    QTcpSocket *cli;
    QString stra;
    QString usestat;
    QString aupass;

};

#endif // LOGIN_H

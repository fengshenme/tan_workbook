#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QBitmap>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QString>

#include "admin.h"
#include "softkeyboard.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QMainWindow {
    Q_OBJECT

public:
    explicit AdminLogin(QWidget* parent = nullptr);
    ~AdminLogin();
    void show_head();

    QPixmap PixmapToRound(const QPixmap& src, int radius);

protected:
    void closeEvent(QCloseEvent* event);

signals:
    void messma(QByteArray msg); //去主界面的
    void regist(QByteArray msg); //去注册界面
    void repas(QByteArray msg); //去密码找回界面

private slots:
    void on_loginG_clicked(); // 登录

    void on_softkeyboard_clicked(); // 软键盘显示

    void on_pushButton_clicked();

private:
    Ui::AdminLogin* ui;
    int count;
};

#endif // ADMINLOGIN_H

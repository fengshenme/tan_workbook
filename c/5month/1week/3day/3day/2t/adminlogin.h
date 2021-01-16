#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include "softkeyboard.h"
#include <QBitmap>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QString>

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QMainWindow {
    Q_OBJECT

public:
    explicit AdminLogin(QWidget* parent = nullptr);
    ~AdminLogin();
    void log_check(bool flag);
    QString load_status();
    bool save_status(QString strstat);
    void show_head(QByteArray msg);
    QPixmap PixmapToRound(const QPixmap& src, int radius);

protected:
    void closeEvent(QCloseEvent* event);

signals:
    void messma(QByteArray msg); //去主界面的
    void regist(QByteArray msg); //去注册界面
    void repas(QByteArray msg); //去密码找回界面

private slots:
    void on_loginG_clicked();

    void on_registB_clicked();

    void mainroute();

    void on_pushButton_clicked();

    void on_usele_textEdited(const QString& arg1);

    void on_usele_editingFinished();

    void on_softkeyboard_clicked();

private:
    Ui::AdminLogin* ui;
    int count;
    QString stra;
    QString usestat;
    QString aupass;
};

#endif // ADMINLOGIN_H

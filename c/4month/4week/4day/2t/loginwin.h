#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <time.h>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class LoginWin;
}

class LoginWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWin(QWidget *parent = nullptr);
    ~LoginWin();

private slots:
    void on_loginbt_clicked();

    void on_registerBt_clicked();

private:
    Ui::LoginWin *ui;
    QSqlDatabase db;
};

#endif // LOGINWIN_H

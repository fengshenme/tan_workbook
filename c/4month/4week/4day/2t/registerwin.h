#ifndef REGISTERWIN_H
#define REGISTERWIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <time.h>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class RegisterWin;
}

class RegisterWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWin(QWidget *parent = nullptr);
    ~RegisterWin();
    void setQSqlDatabase(QSqlDatabase d);

protected:
    void closeEvent(QCloseEvent *event) ;

private slots:
    void on_registerBt_clicked();

private:
    Ui::RegisterWin *ui;
    QSqlDatabase db;

};

#endif // REGISTERWIN_H

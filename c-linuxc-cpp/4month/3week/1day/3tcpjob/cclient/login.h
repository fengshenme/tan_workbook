#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QString>

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

signals:
    void mysignal(QString, QString);

private:
    Ui::Login *ui;
    int count;
};

#endif // LOGIN_H

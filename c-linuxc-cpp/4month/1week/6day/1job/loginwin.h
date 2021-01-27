#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWin; }
QT_END_NAMESPACE

class LoginWin : public QMainWindow
{
    Q_OBJECT

public:
    LoginWin(QWidget *parent = nullptr);
    ~LoginWin();

private slots:
    void on_loginG_clicked();

signals:
    void mysignal(QString, QString);

private:
    Ui::LoginWin *ui;
    int count;
};
#endif // LOGINWIN_H

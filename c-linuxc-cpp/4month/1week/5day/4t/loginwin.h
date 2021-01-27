#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QMainWindow>

namespace Ui {
class loginwin;
}

class loginwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginwin(QWidget *parent = 0);
    ~loginwin();

private slots:
    void on_loginbt_clicked();
//自定义信号--》传递参数给主界面
signals:
    void mysignal(QString,QString);
private:
    Ui::loginwin *ui;
};

#endif // LOGINWIN_H

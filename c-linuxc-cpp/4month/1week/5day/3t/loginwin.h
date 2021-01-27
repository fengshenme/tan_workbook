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

    //自定义信号
signals: //声明信号
    void mysignal(QString, QString); //带参数的信号
private slots: //自定义槽函数
    void on_loginbt_clicked();


private:
    Ui::loginwin *ui;
};

#endif // LOGINWIN_H

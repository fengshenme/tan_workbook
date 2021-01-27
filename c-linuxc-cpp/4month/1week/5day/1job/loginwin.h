#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class LoginWin : public QMainWindow
{
    Q_OBJECT

public:
    LoginWin(QWidget *parent = nullptr);
    ~LoginWin();

private:
    Ui::LoginWin *ui;
};
#endif // MAINWINDOW_H

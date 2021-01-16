#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <QIODevice>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void func();
    void func2();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer * serv;
    QTcpSocket *soc;
};
#endif // MAINWINDOW_H

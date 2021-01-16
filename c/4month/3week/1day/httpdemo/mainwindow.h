#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_downbt_clicked();
    void fun(QNetworkReply*);
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager manager;
};

#endif // MAINWINDOW_H

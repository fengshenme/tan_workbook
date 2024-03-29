#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mycamera.h"
#include <QTimer>

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
    void on_startbt_clicked();


    void on_closebt_clicked();
    void timeFunc();

private:
    Ui::MainWindow *ui;
    mycamera *mycam;
    QTimer *qtime;

};

#endif // MAINWINDOW_H

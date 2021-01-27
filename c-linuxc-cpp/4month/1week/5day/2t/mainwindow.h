#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void com_func();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::MainWindow *ui;

    QString com;
};

#endif // MAINWINDOW_H

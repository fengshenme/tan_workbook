#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startbt_clicked();

    void on_closebt_clicked();

    void on_startbt_2_clicked();

    void on_startbt_3_clicked();


    void on_closebt_2_clicked();

    void on_closebt_3_clicked();


private:
    Ui::MainWindow *ui;
    int ledfd; //led的文件描述符，方便代码中使用
};
#endif // MAINWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QIODevice>
#include <QListWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QMetaEnum>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void serprint();

    void on_close_button_clicked();

    void timeFunc();

    void on_clear_button_clicked();

    void on_send_button_clicked();

private:
    Ui::MainWindow* ui;
    QSerialPort* sport;
    bool port_flag;
    QListWidget* chatlistwid;
    QTimer* qtime;
};
#endif // MAINWINDOW_H

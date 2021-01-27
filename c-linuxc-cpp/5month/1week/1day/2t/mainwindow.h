#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMetaEnum>
#include <QString>
#include <QDebug>
#include <QMessageBox>


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
    void on_portcbox_activated(const QString &arg1);

    void on_portcbox_2_activated(const QString &arg1);

    void on_portcbox_3_activated(const QString &arg1);

    void on_portcbox_4_activated(const QString &arg1);

    void on_portcbox_5_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *sport;
    bool port_flag;
};
#endif // MAINWINDOW_H

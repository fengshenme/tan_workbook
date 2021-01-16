#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <QIODevice>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QMap>


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
    void discont();

    void on_pushButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QTcpServer * serv;
    QTcpSocket *soc;

    QString  uselist;
    QMap<QString, QTcpSocket *> *map;
};
#endif // MAINWINDOW_H

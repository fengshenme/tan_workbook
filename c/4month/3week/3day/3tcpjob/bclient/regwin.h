#ifndef REGWIN_H
#define REGWIN_H

#include <QMainWindow>

#include <QDebug>
#include <QUrl>

#include <QFile>
#include <QByteArray>
#include <QMessageBox>
#include <QTcpSocket>


namespace Ui {
class RegWin;
}

class RegWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegWin(QWidget *parent = nullptr,  QTcpSocket *cl = NULL);
    RegWin();
    ~RegWin();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_registerbt_clicked();

    void on_comboBox_activated(int index);

    void feedback(QByteArray msg);

private:
    Ui::RegWin *ui;
    int ind;
    QList<QString> lis;
    QTcpSocket *cli;

};

#endif // REGWIN_H

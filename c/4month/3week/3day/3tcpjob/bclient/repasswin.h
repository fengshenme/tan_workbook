#ifndef REPASSWIN_H
#define REPASSWIN_H

#include <QDialog>
#include <QDebug>
#include <QUrl>

#include <QFile>
#include <QByteArray>
#include <QMessageBox>
#include <QTcpSocket>

namespace Ui {
class RePassWin;
}

class RePassWin : public QDialog
{
    Q_OBJECT

public:
    explicit RePassWin(QWidget *parent = nullptr, QTcpSocket *cl = NULL);
    ~RePassWin();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_comboBox_activated(int index);

    void on_repass_clicked();

    void rep_feed_back(QByteArray msg);

private:
    Ui::RePassWin *ui;
    int ind;
    QList<QString> lis;
    QTcpSocket *cli;
};

#endif // REPASSWIN_H

#ifndef REGWIN_H
#define REGWIN_H

#include <QWidget>
#include <QMainWindow>

#include <QDebug>
#include <QUrl>

#include <QFile>
#include <QByteArray>
#include <QMessageBox>


namespace Ui {
class RegWin;
}

class RegWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegWin(QWidget *parent = nullptr);
    ~RegWin();

private slots:
    void on_registerbt_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::RegWin *ui;
    int ind;
    QList<QString> lis;
};

#endif // REGWIN_H

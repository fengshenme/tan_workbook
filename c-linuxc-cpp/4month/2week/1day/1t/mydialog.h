#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDebug>
#include <QPushButton>

class MyDialog : public QDialog
{
    Q_OBJECT;
public:
    MyDialog();
    ~MyDialog();

    QLineEdit *usre;
    QPushButton *bt1;
    QPushButton *bt2;

private slots:
    void on_bt1_clicked();

};

#endif // MYDIALOG_H

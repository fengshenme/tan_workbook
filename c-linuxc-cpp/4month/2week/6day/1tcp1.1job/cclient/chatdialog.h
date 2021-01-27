#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>
#include <QFileDialog>

#include <QCloseEvent>
#include <QTcpSocket>

class ChatDialog: public QDialog
{

     Q_OBJECT;
public:
    ChatDialog(QWidget *parent = 0);
    ChatDialog(QWidget *parent = 0, QString ipa = "default", QTcpSocket *cli = 0);
    ~ChatDialog();

public slots:
    void to_msg(QByteArray msg);

protected:
    void closeEvent(QCloseEvent *event);



private slots:
       void on_sendmess_clicked();
       void on_sendexpr_clicked();


private:
    QTextEdit *chatte;
    QPushButton *sendmess;
    QPushButton *sendexpr;
    QListWidget *chatlistwid;

    QTcpSocket *cli;
    QString stra;
};

#endif // CHATDIALOG_H

#ifndef MYKEYBOARD_H
#define MYKEYBOARD_H


#include <QWidget>
#include <QPushButton>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QApplication>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MyKeyBoard;
}
QT_END_NAMESPACE

class MyKeyBoard : public QWidget
{
    Q_OBJECT

public:
     MyKeyBoard(QWidget *parent = nullptr);
    ~MyKeyBoard();
    bool transflags;

public slots:
    void transUpperOrLower();
    void keyEvent();

signals:
    void trans();

private:
    Ui::MyKeyBoard *ui;
    QList<QPushButton *> mblist;
};

#endif // SOFTKEYBOARD_H

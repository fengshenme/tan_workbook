#ifndef MYKEYBOARD_H
#define MYKEYBOARD_H

#include <QWidget>
#include "mybutton.h"

namespace Ui {
class MyKeyBoard;
}

class MyKeyBoard : public QWidget
{
    Q_OBJECT

public:
    explicit MyKeyBoard(QWidget *parent = nullptr);
    ~MyKeyBoard();
    void transLower();
    bool transflags;

private:
    Ui::MyKeyBoard *ui;
    QList<MyButton *> mblist;
};

#endif // MYKEYBOARD_H

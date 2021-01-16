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
    bool transflags;
public slots:
    void transUpperOrLower();



private:
    Ui::MyKeyBoard *ui;
};

#endif // MYKEYBOARD_H

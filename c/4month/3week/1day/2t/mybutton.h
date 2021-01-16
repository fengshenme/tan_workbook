#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QApplication>
#include <QDebug>


#include "mykeyboard.h"




class MyButton : public QPushButton
{
         Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    ~MyButton();

public slots:
    void func();

private:
    MyKeyBoard *pare;
};

#endif // MYBUTTON_H

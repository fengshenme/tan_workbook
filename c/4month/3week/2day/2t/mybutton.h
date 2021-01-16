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
     MyButton(QWidget *parent = nullptr);
     MyButton();
    ~MyButton();

public slots:
    void func();
signals:
    void trans();

private:

};

#endif // MYBUTTON_H

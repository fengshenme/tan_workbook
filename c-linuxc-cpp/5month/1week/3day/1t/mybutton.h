#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget *parent = nullptr);
    MyButton();

public slots:
    void on_pressed();
    void on_released();
};

#endif // MYBUTTON_H

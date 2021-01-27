#include "mybutton.h"

MyButton::MyButton(QWidget *parent):QPushButton(parent)
{
    connect(this, SIGNAL(pressed()), this, SLOT(on_pressed()));
    connect(this, SIGNAL(released()), this, SLOT(on_released()));
}

void MyButton::on_pressed()
{
    this->setStyleSheet("background-color: rgb(136, 138, 133);");
}

void MyButton::on_released()
{
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
}

#include "mykeyboard.h"
#include "ui_mykeyboard.h"

MyKeyBoard::MyKeyBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyKeyBoard)
{
    ui->setupUi(this);


}

MyKeyBoard::~MyKeyBoard()
{
    delete ui;
}

#include "contlamp.h"
#include "ui_contlamp.h"

ContLamp::ContLamp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContLamp)
{
    ui->setupUi(this);
}

ContLamp::~ContLamp()
{
    delete ui;
}

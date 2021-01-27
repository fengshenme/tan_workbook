#include "mydialog.h"


MyDialog::MyDialog()
{



    this->setWindowTitle("一个对话框");
    usre = new QLineEdit(this);

    usre->setGeometry(30, 90, 100, 30);

    bt1 = new QPushButton(this);

    bt1->setGeometry(50, 120, 50, 30);
    bt1->setText("启动");

    bt2 = new QPushButton(this);

    bt2->setGeometry(120, 120, 50, 30);
    bt2->setText("发送");

    connect(bt1, SIGNAL(clicked()), this, SLOT(on_bt1_clicked));

}

MyDialog::~MyDialog()
{

}

void MyDialog::on_bt1_clicked()
{

}

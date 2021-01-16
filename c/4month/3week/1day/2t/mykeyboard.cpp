#include "mykeyboard.h"
#include "ui_mykeyboard.h"

MyKeyBoard::MyKeyBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyKeyBoard)
{
    ui->setupUi(this);
    QRegExp rx("pushButton_*");
     mblist = this->findChildren<MyButton *>(rx);
    qDebug() << mblist.size();

    transflags = true;


}

MyKeyBoard::~MyKeyBoard()
{
    delete ui;
}

void MyKeyBoard::transLower()
{

    for (int var = 0; var < mblist->size(); ++var) {

        qDebug() <<  mblist->at(var)->text();
//        mb->text().toLower();

//        mb->setText( );
    }


}

#include "mykeyboard.h"
#include "ui_mykeyboard.h"


 QList<MyButton *> mblist;

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



void MyKeyBoard::transUpperOrLower()
{

    MyButton * mb = NULL;
    if(transflags)
    {
        for (int var = 0; var < mblist.size(); ++var) {

            mb = mblist.at(var);
            QString str = mb->text();

            mb->setText(str.toLower());

             qDebug() << mb->text();
        }
        transflags = false;
        mblist.clear();

    }
    else
    {
        for (int var = 0; var < mblist.size(); ++var) {

            mb = mblist.at(var);
            QString str = mb->text();
            qDebug() <<  str;

            mb->setText(str.toUpper());
        }
        transflags = true;
    }

}

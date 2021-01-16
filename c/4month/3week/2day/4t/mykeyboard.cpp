#include "mykeyboard.h"
#include "ui_mykeyboard.h"



MyKeyBoard::MyKeyBoard(QWidget *parent) : QWidget(parent), ui(new Ui::MyKeyBoard)
{

    ui->setupUi(this);

    QRegExp rx("pushButton_*");
    mblist = this->findChildren<QPushButton *>(rx);
    qDebug() << mblist.size();

    transflags = true;

    for (int var = 0; var < mblist.size(); ++var)
    {
        connect(mblist.at(var), SIGNAL(clicked(bool)), this, SLOT(keyEvent()));

    }
    connect(this, SIGNAL(trans()), this, SLOT(transUpperOrLower()));

}

MyKeyBoard::~MyKeyBoard()
{
    delete ui;
}



void MyKeyBoard::transUpperOrLower()
{

    QPushButton * mb = NULL;

    for (int var = 0; var < mblist.size(); ++var)
    {
         mb = mblist.at(var);
        if(transflags)
            mb->setText(mb->text().toLower());
        else
            mb->setText(mb->text().toUpper());
    }

    transflags = !transflags;

}

void MyKeyBoard::keyEvent()
{
    //获取信号的发送者
    QPushButton *mbt = qobject_cast<QPushButton *>(sender());
    QKeyEvent *keyeve = NULL;
    QString strkey = mbt->text();
    //    strkey = strkey.toLower();
    if( strkey == "<-")
        keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, strkey);
    else if(  QString::compare(strkey, "enter", Qt::CaseInsensitive) == 0)
        keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, strkey);
    else if( QString::compare(strkey, "space", Qt::CaseInsensitive) == 0 )
        keyeve = new QKeyEvent(QEvent::KeyPress, 32, Qt::NoModifier, " ");
    else if( QString::compare(strkey, "tab", Qt::CaseInsensitive) == 0  )
        //       keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier, "   ");
        keyeve = new QKeyEvent(QEvent::KeyPress, 13, Qt::NoModifier, "   ");
    else if( QString::compare(strkey, "capslock", Qt::CaseInsensitive) == 0  )
    {
        emit trans();
        keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_CapsLock, Qt::NoModifier, "");
    }
    else
        keyeve = new QKeyEvent(QEvent::KeyPress, strkey.toInt() - 32, Qt::NoModifier, strkey);

    //QT中有个函数可以获取鼠标光标进入的组件
    QCoreApplication::sendEvent(QApplication::focusWidget(), keyeve);
}



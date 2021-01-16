#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

    pare = (MyKeyBoard *)parent;
    connect(this, SIGNAL(clicked(bool)), this, SLOT(func()));
}

MyButton::~MyButton(){}

void MyButton::func()
{
    //获取信号的发送者
   MyButton *mbt = qobject_cast<MyButton *>(sender());
   QKeyEvent *keyeve = NULL;
   QString strkey = mbt->text();
   strkey = strkey.toLower();
   if( strkey == "<-")
        keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, strkey);
   else if( strkey == "enter")
        keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, strkey);
   else if( strkey == "space")
       keyeve = new QKeyEvent(QEvent::KeyPress, 32, Qt::NoModifier, " ");
   else if( strkey == "tab")
//       keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier, "   ");
   keyeve = new QKeyEvent(QEvent::KeyPress, 13, Qt::NoModifier, "   ");
   else if( strkey == "capslock")
   {

       //       qDebug() << pare->pushButton_1->text();
        keyeve = new QKeyEvent(QEvent::KeyPress, Qt::Key_CapsLock, Qt::NoModifier, strkey);
   }
   else
      keyeve = new QKeyEvent(QEvent::KeyPress, strkey.toInt(), Qt::NoModifier, strkey);

   //QT中有个函数可以获取鼠标光标进入的组件
   QCoreApplication::sendEvent(QApplication::focusWidget(), keyeve);
}



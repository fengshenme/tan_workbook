#include "chatthread.h"



ChatThread::ChatThread(QWidget *parent):QThread(parent)
{

}

ChatThread::~ChatThread()
{

}

void ChatThread::run()
{

//     mal = new ChatDialog();

//    mal->resize(500, 500);
//    mal->setAttribute(Qt::WA_DeleteOnClose);
//    mal->show();

    flags = true;
    //    QString str;
    //    while (flags) {

    //    }
    qDebug() << "das;ld ---";
//    return ;
}

void ChatThread::stop()
{
    flags = false;
}



#include "mythread.h"


MyThread::MyThread()
{
}

MyThread::MyThread(QLabel *lb)
{
    this->lb = lb;
}

void MyThread::run()
{
    flags = true;
    int i = 23;
    QString str;
    while (flags) {

        str = QString("D:/data/tupian/image_bin/%1.jpg").arg(i);
        QPixmap pix(str);
        lb->setPixmap(pix);
        i++;
        QThread::sleep(1);
        qDebug() << "hello" ;
        qDebug() << str ;
        if(i > 25)
            i = 23;
    }

    return ;
}

void MyThread::stop()
{
    flags = false;
}

#include "mythread.h"

MyThread::MyThread()
{

}

void MyThread::run()
{

    while (1) {
        qDebug() << "hello" ;
        QThread::sleep(1);
    }

    return ;
}

#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>
#include <QLabel>
#include <QPixmap>

class MyThread : public QThread
{


public:

    MyThread();
    MyThread(QLabel *lb);

    void run();
    void stop();
private:
    bool flags;
    QLabel *lb;
};

#endif // MYTHREAD_H

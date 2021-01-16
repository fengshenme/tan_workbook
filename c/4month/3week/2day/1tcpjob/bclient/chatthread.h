#ifndef CHATTHREAD_H
#define CHATTHREAD_H

#include <QThread>
#include <QDebug>
#include <QListWidget>

#include "chatdialog.h"

class ChatThread : public QThread
{


public:
    ChatThread(QWidget *parent = 0);
    ~ChatThread();
    void run() ;
    void stop();
    ChatDialog *mal;


private:
    bool flags;

};

#endif // CHATTHREAD_H

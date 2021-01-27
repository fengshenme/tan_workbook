#include "loginwin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWin w;
    w.show();

    qSetMessagePattern("   debug:[%{file}:%{line}]%{message}");

    return a.exec();
}

#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{


    //打印行号
    qSetMessagePattern("[%{file}:%{line}:%{function}] %{message}");

    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}

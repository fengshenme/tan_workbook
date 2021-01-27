#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    //打印行号
    qSetMessagePattern("[%{time yyyyMMdd h:mm:ss.zzz}:%{file}:%{line}:%{function}] %{message}");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qSetMessagePattern("   debug:[%{file}:%{line}]%{message}");

    return a.exec();
}

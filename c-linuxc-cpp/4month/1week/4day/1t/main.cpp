#include <QCoreApplication>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int aa = 100;
    float bb = 10.2;
    QString q1 = "N你好";

    QString qstr2 = QString("%1,%2,%3").arg(aa).arg(bb).arg(q1);

    qDebug() << qstr2;





    return a.exec();
}

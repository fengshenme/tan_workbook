#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("H:/git-repo/qtdata/testcodec.txt");

    file.open(QIODevice::WriteOnly | QIODevice::Append);


//        ff10 ff59

    QByteArray bty;


    QString ass = "\uff11";

//    char *sch = new char[0xffff];



//    QString str;
    unsigned char i, y;
    int c = 0, d = 0;


    for(i = 0x00; i < 0xff ; i++)
    {

        for(y = 0x00; y < 0xff ; y++)
        {

        bty.append(i);
        bty.append(y);
//        bty.append(a3 + i);
        qDebug() << bty;
        file.write(bty);
        bty.clear();

        }



    }



    file.close();

    return a.exec();
}

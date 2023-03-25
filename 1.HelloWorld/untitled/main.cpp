#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    qDebug()<<"hello word";

    return a.exec();
}

#include <QCoreApplication>
#include "myudp.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyUDP server;
    MyUDP client;

    client.sayHello();
    return a.exec();
}

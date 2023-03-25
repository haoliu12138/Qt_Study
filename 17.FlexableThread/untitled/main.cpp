#include <QCoreApplication>
#include <QThread>
#include "myobject.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyObject myObj;
    QThread thread;
    myObj.setUp(&thread);
    myObj.moveToThread(&thread);
    thread.start();
    return a.exec();
}

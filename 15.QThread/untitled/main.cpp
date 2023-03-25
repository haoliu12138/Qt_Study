#include <QCoreApplication>
#include "mythread.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread t1;
    MyThread t2;


    t1.TName="Thread1";
    //t2.TName="Thread2";


    t1.start(QThread::HighestPriority);
    //t2.start();
    //加了wait就是表示需要先等我这个线程执行完再执行后面的
    t1.Stop=true;
    t1.wait();

    qDebug()<<"here";

    return a.exec();
}

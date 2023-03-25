#include "mythread.h"
#include <QDebug>
MyThread::MyThread()
{

}
void MyThread::run()
{
    QMutex mutex;
    mutex.lock();
    qDebug()<<this->TName<<" is running";
    for(int i=0;i<10;i++)
    {

        if(this->Stop)
        {

            break;

        }

        qDebug()<<this->TName<<":"<<i;
        this->msleep(100);

    }
    mutex.unlock();
}

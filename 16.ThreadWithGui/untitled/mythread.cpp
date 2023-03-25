#include "mythread.h"
#include <QMutex>
#include <QDebug>
MyThread::MyThread()
{

}

void MyThread::run()
{
    qDebug()<<"Thread is running";
    for(int i=0;i<100;i++)
    {
        QMutex mutex;
        mutex.lock();
        qDebug()<<QString::number(this->stop);
        if(this->stop==true)
        {
            break;
        }
        mutex.unlock();
        //这个sleep方法和QT4有所不同分成了sleep参数表示线程挂起的秒数，msleep 参数表示挂起的毫秒数
        //this->sleep(1);
        emit valueChange(i);
        this->msleep(1000);

    }
}

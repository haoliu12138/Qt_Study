#include "myobject.h"
#include <QDebug>
MyObject::MyObject(QObject *parent) : QObject(parent)
{

}
void MyObject::setUp(QThread* thread)
{
    this->thread=thread;
    connect(thread,&QThread::started,this,&MyObject::DoWork);
}
void MyObject::DoWork()
{
    for(int i=0;i<100;i++)
    {
        qDebug()<<QString::number(i);
        thread->sleep(1);
    }
}

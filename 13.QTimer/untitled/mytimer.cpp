#include "mytimer.h"
#include <QDebug>

MyTimer::MyTimer()
{
   timer=new QTimer(this);

   connect(timer,&QTimer::timeout,this,&MyTimer::MySlot);

   timer->start(1000);

}
void MyTimer::MySlot()
{
    qDebug()<<"Time out";
}

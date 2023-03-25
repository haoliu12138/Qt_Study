#include "mytask.h"

MyTask::MyTask()
{

}
void MyTask::run()
{
    qDebug()<<"task start";

    int iNumber=0;
    for(int i=0;i<100;i++)
    {
        iNumber+=i;
    }
    qDebug()<<"task done";

    emit Result(iNumber);
}

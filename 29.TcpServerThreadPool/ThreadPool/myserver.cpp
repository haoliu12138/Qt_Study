#include "myserver.h"

MyServer::MyServer()
{
    pool=new QThreadPool(this);
}
void MyServer::StartServer()
{
    if(!this->listen(QHostAddress::Any,1234))
    {
        qDebug()<<"cound not start server";
    }
    else
    {
        qDebug()<<"Listening.....";
    }
}
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    MyRunnable* task=new MyRunnable();
    task->setAutoDelete(true);

    task->SocketDescriptor=socketDescriptor;
    pool->start(task);
}

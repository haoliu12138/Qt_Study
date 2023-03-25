#include "myserver.h"

MyServer::MyServer():QTcpServer()
{

}
void MyServer::StartServer()
{
    if(!this->listen(QHostAddress::Any,6666))
    {
        qDebug()<<"Could not start server";
    }
    else
    {
        qDebug()<<"Listening....";
    }
}
void MyServer::incomingConnection(qintptr handle)
{
    qDebug()<<handle<<" Connecting";
    MyThread* thread=new MyThread(handle);

    connect(thread,&MyThread::finished,thread,&MyThread::deleteLater);
    thread->start();
}

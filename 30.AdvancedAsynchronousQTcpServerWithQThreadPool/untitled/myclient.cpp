#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(15);
}
void MyClient::SetSocket(int Descriptor)
{
    socket=new QTcpSocket(this);
    connect(socket,&QTcpSocket::connected,this,&MyClient::connected);
    connect(socket,&QTcpSocket::disconnected,this,&MyClient::disconnected);
    connect(socket,&QTcpSocket::readyRead,this,&MyClient::readyRead);

    socket->setSocketDescriptor(Descriptor);

    qDebug()<<"client connected";
}

void MyClient::connected()
{
    qDebug()<<"client connected event";
}

void MyClient::disconnected()
{
    qDebug()<<"client disconnected";

}
void MyClient::readyRead()
{
    qDebug()<<socket->readAll();

    //耗时操作
    MyTask* task=new MyTask();
    task->setAutoDelete(true);
    connect(task,&MyTask::Result,this,&MyClient::TaskResult,Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(task);
}
void MyClient::TaskResult(int number)
{
    QByteArray Buffer;
    Buffer.append("\r\nTask Result ");
    Buffer.append(QString::number(number));
    socket->write(Buffer);

}

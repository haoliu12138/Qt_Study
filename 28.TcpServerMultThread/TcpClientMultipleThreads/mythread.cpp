#include "mythread.h"

MyThread::MyThread(int ID)
{
    this->socketDescriptor=ID;
}

void MyThread::run()
{
    //开启进程
    qDebug()<<this->socketDescriptor<<" Starting Thread";

    socket=new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }
    //注意这个第三个参数有所不同
    connect(socket,&QTcpSocket::readyRead,this,&MyThread::readyRead,Qt::DirectConnection);
    connect(socket,&QTcpSocket::disconnected,this,&MyThread::disconnected,Qt::DirectConnection);

    qDebug()<<this->socketDescriptor<<" Client connected";
    //加了这个防止线程执行结束
    exec();

}
void MyThread::readyRead()
{
    //接受到数据在服务端打印
    QByteArray Data=socket->readAll();

    qDebug()<<this->socketDescriptor<<" Data in: "<<Data;
    //将数据再回写到客户端
    //socket->write(Data);
}

void MyThread::disconnected()
{
    qDebug()<<this->socketDescriptor<<" Client disconnected";

    socket->deleteLater();
    exit(0);
}

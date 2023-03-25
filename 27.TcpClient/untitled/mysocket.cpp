#include "mysocket.h"

MySocket::MySocket(QObject *parent) : QObject(parent)
{


}
void MySocket::Test()
{
    socket=new QTcpSocket(this);

    connect(socket,&QTcpSocket::connected,this,&MySocket::connected);
    connect(socket,&QTcpSocket::disconnected,this,&MySocket::disconnected);
    connect(socket,&QTcpSocket::readyRead,this,&MySocket::readyRead);
    connect(socket,&QTcpSocket::bytesWritten,this,&MySocket::bytesWritten);

    qDebug()<<"connecting ....";
    //连接到主机
    socket->connectToHost("127.0.0.1",1234);
    //连接等待
    if(!socket->waitForConnected(3))
    {
        qDebug()<<"Error "<<socket->errorString();
    }
}
void MySocket::connected()
{

    qDebug()<<"connected";

    socket->write("hello server");
    //socket->flush();

}
void MySocket::disconnected()
{
    qDebug()<<"disconnected";
}
void MySocket::bytesWritten(qint64 bytes)
{
    qDebug()<<"we wrote: "<<bytes;
}
void MySocket::readyRead()
{
    qDebug()<<"reading";
    qDebug()<< socket->readAll();
}

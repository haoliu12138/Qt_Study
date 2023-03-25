#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server=new QTcpServer(this);

    connect(server,&QTcpServer::newConnection,this,&MyServer::newConnection);


    if(!server->listen(QHostAddress::Any,1234))
    {
        qDebug()<<"server not start";
    }
    else
    {
        qDebug()<<"server  start";
    }
}
void MyServer::newConnection()
{
        QTcpSocket *socket=server->nextPendingConnection();

        connect(socket,&QTcpSocket::readyRead,[=](){
            qDebug()<<"aa"<<socket->readAll();
        });

        socket->write("hello client\r\n");
        socket->flush();


        socket->waitForBytesWritten(3000);

        //socket->close();
}

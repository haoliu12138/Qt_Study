#include "myudp.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket=new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket,&QUdpSocket::readyRead,this,&MyUDP::readyRead);
}
void MyUDP::sayHello()
{
    QByteArray buffer;
    buffer.append("hello udp");
    socket->writeDatagram(buffer,QHostAddress::LocalHost,1234);
}
void MyUDP::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(buffer.data(),buffer.size(),&sender,&senderPort);

    qDebug()<<sender.toString();
    qDebug()<<senderPort;
    qDebug()<<buffer;

}

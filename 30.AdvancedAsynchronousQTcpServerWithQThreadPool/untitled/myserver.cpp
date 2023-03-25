#include "myserver.h"

MyServer::MyServer()
{

}
void MyServer::StartServer()
{
    if(listen(QHostAddress::Any,1234))
    {
        qDebug()<<"listening...";
    }
    else
    {
        qDebug()<<"not listen";
    }
}
void MyServer::incomingConnection(qintptr handle)
{
    MyClient* client=new MyClient();
    client->SetSocket(handle);
}

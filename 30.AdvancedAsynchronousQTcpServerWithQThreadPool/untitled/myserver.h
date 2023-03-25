#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "myclient.h"
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer();
    void StartServer();
protected:
    void incomingConnection(qintptr handle);
};

#endif // MYSERVER_H

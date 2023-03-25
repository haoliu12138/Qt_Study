#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QObject>
#include <QDebug>
#include "mythread.h"
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer();

    void StartServer();
protected:
    //
    virtual void incomingConnection(qintptr handle);
};

#endif // MYSERVER_H

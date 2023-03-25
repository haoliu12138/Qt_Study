#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include "myrunnable.h"
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer();
    void StartServer();
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
    QThreadPool* pool;
};

#endif // MYSERVER_H

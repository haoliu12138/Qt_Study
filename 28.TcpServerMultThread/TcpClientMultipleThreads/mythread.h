#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(int ID);

    void run();

    QTcpSocket* socket;
    int socketDescriptor;
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead();
    void disconnected();

};

#endif // MYTHREAD_H

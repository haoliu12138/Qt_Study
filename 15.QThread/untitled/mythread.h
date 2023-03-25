#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCOre>

class MyThread : public QThread
{
public:
    MyThread();
    void run();

    QString TName;
    bool Stop=false;
};

#endif // MYTHREAD_H

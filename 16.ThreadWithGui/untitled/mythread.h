#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run();
    bool stop=false;
signals:
    void valueChange(int);
public slots:

};

#endif // MYTHREAD_H

#include "myrunnable.h"

MyRunnable::MyRunnable()
{

}
void MyRunnable::run()
{
    if(!this->SocketDescriptor) return;

    QTcpSocket socket;
    socket.setSocketDescriptor(this->SocketDescriptor);

    socket.write("hello word");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();
}

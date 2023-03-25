#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir;
    //获取所有驱动器路径就是磁盘
    foreach(QFileInfo info,dir.drives())
    {
        qDebug()<<info.absolutePath();

    };
    QDir dir1("C:\\");
    foreach(QFileInfo info,dir1.entryInfoList())
    {
        if(info.isDir()) qDebug()<<"Dir"<<info.absoluteFilePath();
        if(info.isFile()) qDebug()<<"File"<<info.absoluteFilePath();
    }





    return a.exec();
}

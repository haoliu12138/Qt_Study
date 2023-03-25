#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
void Wirte(QString FileName)
{
    QFile file(FileName);

    qDebug()<<file.exists();
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        qDebug()<<"file cannot opne";
        return;
    }
    QTextStream out(&file);

    out<<"hello word";

    file.flush();
    file.close();

}
void Read(QString FileName)
{

    QFile file(FileName);

     qDebug()<<file.exists();

    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<<"file cannot read";
        return;
    }
    QTextStream in(&file);

    QString str=in.readAll();

    qDebug()<<str;

    file.flush();
    file.close();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //这里文件名和视频中介绍的不同需要加两个 \ 才行
    Wirte("C:\\test\\test.txt");

    Read("C:\\test\\test.txt");

    Read("C:\\Users\\hao\\Desktop\\QtProjects\\11.QFile\\untitled\\untitled.pro");

    return a.exec();
}

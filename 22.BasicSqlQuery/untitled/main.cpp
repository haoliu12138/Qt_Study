#include <QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //创建db对象
    QSqlDatabase db=QSqlDatabase::addDatabase("QOCI");
    //设置host 端口 db名
    db.setDatabaseName(QString("%1:%2/%3").arg("192.168.1.5").arg(1521).arg("OCP12CPDB"));
    db.setUserName("apps");
    db.setPassword("0528");

    if(db.open())
    {
        qDebug()<<"oracle connect success";

        QSqlQuery qry;

        qry.prepare("insert into cux_users values (:name,:password)");

        qry.bindValue(":name","haohao");
        qry.bindValue(":password","66666");

        if(qry.exec())
        {
            while(qry.next())
            {
                qDebug()<<"insert success";
            }


        }
        else
        {
            qDebug()<<"Error= "<<db.lastError().text();
        }

    }
    else
    {
        qDebug()<<"oracle connect fail";
        qDebug()<<"Error= "<<db.lastError().text();

    }

    //db.close();
    return a.exec();
}

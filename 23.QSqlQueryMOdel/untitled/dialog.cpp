#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //创建db对象
    QSqlDatabase db=QSqlDatabase::addDatabase("QOCI");
    //设置host 端口 db名
    db.setDatabaseName(QString("%1:%2/%3").arg("192.168.1.5").arg(1521).arg("OCP12CPDB"));
    db.setUserName("apps");
    db.setPassword("0528");

    db.open();

    model=new QSqlQueryModel();
    //这种方法不能改
    model->setQuery("select * from cux_users");


    ui->tableView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}

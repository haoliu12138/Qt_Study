#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //创建db对象
    db=QSqlDatabase::addDatabase("QOCI");
    //设置host 端口 db名
    db.setDatabaseName(QString("%1:%2/%3").arg("192.168.1.5").arg(1521).arg("OCP12CPDB"));
    db.setUserName("apps");
    db.setPassword("0528");

    db.open();

    model=new QSqlTableModel();
    model->setTable("cux_users");
    model->select();

    ui->tableView->setModel(model);

    //db.close();
}

Dialog::~Dialog()
{
    delete ui;
}

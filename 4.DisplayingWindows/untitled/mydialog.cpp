#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    qDebug()<<"dialog create";
    ui->setupUi(this);
}

myDialog::~myDialog()
{
    qDebug()<<"dialog delete";
    delete ui;
}

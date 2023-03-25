#include "dialog.h"
#include "ui_dialog.h"
#include "filter.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->pushButton->setWhatsThis("<a href='www.google.com'>This is a link</a>");

    Filter* filter=new Filter;

    this->installEventFilter(filter);

    connect(filter,&Filter::linkClicked,this,&Dialog::showLink);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::showLink(const QString &link)
{
    QMessageBox::information(this,"Link",link);
}

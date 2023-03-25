#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread=new MyThread();

    connect(thread,&MyThread::valueChange,this,&Widget::changeValue);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeValue(int Number){
    ui->label->setText(QString::number(Number));
}
void Widget::on_pushButton_clicked()
{
    qDebug()<<"start";
    thread->start();
}

void Widget::on_pushButton_2_clicked()
{
    qDebug()<<"stop";
    thread->stop=true;
}

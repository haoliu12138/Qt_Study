#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"create window";
    ui->setupUi(this);
    //让文本框成为窗口的中心组件，这样会让文本框占据整个窗口
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    qDebug()<<"delete window";
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{

    myDialog* mydialog =new myDialog();
    mydialog->show();
//    mydialog->setModal(true);
//    mydialog->exec();
}

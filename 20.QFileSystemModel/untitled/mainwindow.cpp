#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path="C:/";

    dirModel=new QFileSystemModel;
    fileModel=new QFileSystemModel;

    dirModel->setRootPath(path);
    dirModel->setFilter(QDir::NoDotAndDotDot|QDir::AllDirs);
    ui->treeView1->setModel(dirModel);

    fileModel->setFilter(QDir::NoDotAndDotDot|QDir::Files);
    fileModel->setRootPath(path);
    ui->treeView2->setModel(fileModel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView1_clicked(const QModelIndex &index)
{
    QString path=dirModel->fileInfo(index).absoluteFilePath();
    qDebug()<<path;
    ui->treeView2->setRootIndex(fileModel->setRootPath(path));
}

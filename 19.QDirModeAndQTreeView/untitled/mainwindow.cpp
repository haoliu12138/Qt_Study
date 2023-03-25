#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model=new QDirModel;
    model->setReadOnly(false);
    model->setSorting(QDir::DirsFirst|QDir::IgnoreCase);

    ui->treeView->setModel(model);

    QModelIndex index=model->index("C:/DevApps/PLSQL");

    //展开目录
    ui->treeView->expand(index);
    //滚动到当前目录
    ui->treeView->scrollTo(index);
    //选中目录
    ui->treeView->setCurrentIndex(index);
    //调整列宽
    ui->treeView->resizeColumnToContents(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QModelIndex index=ui->treeView->currentIndex();

    if(!index.isValid()) return;

    QString name=QInputDialog::getText(this,"Inpurt Name","Enter an name");

    if(name.isEmpty()) return;

    model->mkdir(index,name);
}

void MainWindow::on_pushButton_2_clicked()
{
    QModelIndex index=ui->treeView->currentIndex();

    if(!index.isValid()) return;

    if(model->fileInfo(index).isDir())
    {
        model->rmdir(index);
    }
    else
    {
        model->remove(index);
    }

}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model=new QStringListModel;

    QStringList list;

    list<<"cats"<<"birds"<<"dogs";

    model->setStringList(list);

    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //获取model的行数
    int rows=model->rowCount();
    //在rows位置插入一行
    model->insertRows(rows,1);
    //获取增加行的index
    QModelIndex index=model->index(rows);
    //将当前行设置为新增的行
    ui->listView->setCurrentIndex(index);
    //编辑新增行
    ui->listView->edit(index);
}

void MainWindow::on_pushButton_2_clicked()
{
    //获取model的行数
    int rows=ui->listView->currentIndex().row();
    //在rows位置插入一行
    model->insertRows(rows,1);
    //获取增加行的index
    QModelIndex index=model->index(rows);
    //将当前行设置为新增的行
    ui->listView->setCurrentIndex(index);
    //编辑新增行
    ui->listView->edit(index);
}

void MainWindow::on_pushButton_3_clicked()
{
    //从当前位置删除一行
    //删除model就会删除view显示的
    model->removeRows(ui->listView->currentIndex().row(),1);

}

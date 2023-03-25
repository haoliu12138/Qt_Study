#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //list widget
    ui->listWidget->addItem("one");
    ui->listWidget->addItem("two");
    ui->listWidget->addItem("three");
    //tree widget
    //root
    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setHeaderLabels(QStringList()<<"name"<<"age");
    QTreeWidgetItem* root=new QTreeWidgetItem();
    root->setText(0,"hao");
    root->setText(1,"0528");
    //root->setText(2,"0528");

    ui->treeWidget->addTopLevelItem(root);
    //son
    QTreeWidgetItem* son=new QTreeWidgetItem();
    //son->setText(0,"son1");
    son->setText(1,"son1");
    son->setText(2,"05281");
    root->addChild(son);


}

MainWindow::~MainWindow()
{
    delete ui;
}

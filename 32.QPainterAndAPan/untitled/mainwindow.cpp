#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QPen pen1(Qt::red);
    pen1.setWidth(4);

    QPen pen2(Qt::black);
    pen2.setWidth(10);

    QPoint p1;
    p1.setX(10);
    p1.setY(10);

    QPoint p2;
    p1.setX(100);
    p1.setY(100);

    painter.setPen(pen1);
    painter.drawLine(p1,p2);

    painter.setPen(pen2);
    painter.drawPoint(p1);
    painter.drawPoint(p2);


}


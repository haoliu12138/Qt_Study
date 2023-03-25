#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    MyThread* thread;

private:
    Ui::Widget *ui;
public slots:
    void changeValue(int);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H

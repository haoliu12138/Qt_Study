#include <QApplication>
#include <QtWidgets>
#include <QtGui>
#include <QTCore>
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    QWidget* win=new QWidget();


    win->setWindowTitle("win");

    QGridLayout* grid=new QGridLayout();

    QLabel* label=new QLabel("Name");
    QLineEdit* edit=new QLineEdit();
    QPushButton* btn=new QPushButton();

    grid->addWidget(label,0,0);
    grid->addWidget(edit,0,1);
    //跨行设置成1，跨两列
    grid->addWidget(btn,1,0,1,2);

    win->setLayout(grid);

    win->show();

    return app.exec();
}

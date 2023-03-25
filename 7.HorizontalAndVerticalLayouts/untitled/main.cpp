#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    QWidget* window=new QWidget();

    QPushButton* btn1=new QPushButton("one");
    QPushButton* btn2=new QPushButton("two");
    QPushButton* btn3=new QPushButton("three");

    QHBoxLayout* HLayout=new QHBoxLayout();
    QVBoxLayout* VLayout=new QVBoxLayout();

    VLayout->addWidget(btn1);
    VLayout->addWidget(btn2);
    VLayout->addWidget(btn3);

    window->setLayout(VLayout);

    window->setWindowTitle("layout");

    window->show();


    return app.exec();
}

#include <QApplication>
#include <QLabel>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    
    QWidget* win=new QWidget();

    win->show();
    
    return app.exec();
}

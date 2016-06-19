#include "widgets.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bs::LoginWindow* lw = new bs::LoginWindow;
    int id = lw->exec();
    delete lw;
    if (id>0)
    {
        bs::MainWindow* w = new bs::MainWindow(id);
        w->show();
    }
    return a.exec();
}

#include "serverwidget.h"
#include "clientweight.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWidget w;
    w.show();

    ClientWeight cw;
    cw.show();

    return a.exec();
}

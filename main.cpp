#include "Header.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    w.setFixedSize(273, 123);
    w.show();


    return a.exec();
}

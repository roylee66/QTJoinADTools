#include "Header.h"
#include <QtWidgets/QApplication>
#include<qscreen.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication1 w;


    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableVirtualGeometry();
    int dWidth = screenRect.width();
    int dHeight = screenRect.height();//桌面大小
    w.move(dWidth - w.width(), 0);//窗口移动到右上角



    w.setFixedSize(275, 120);//275,140
    w.show();
    return a.exec();
}

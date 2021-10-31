#include "dec2led.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dec2Led w;
    w.show();

    return a.exec();
}

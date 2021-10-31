// GpioClient/main.cpp

#include "gpioclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GpioClient w;
    w.show();

    return a.exec();
}

// GpioMonitor/main.cpp

#include <QCoreApplication>
#include "sender.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Sender sender;
    return a.exec();
}

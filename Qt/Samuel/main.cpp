#include "samuel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Samuel w;
    w.show();

    return a.exec();
}

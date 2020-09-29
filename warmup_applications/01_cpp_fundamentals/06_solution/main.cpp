#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "header.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.setInterval(500);

    Hans hans;

    QObject::connect(&timer, &QTimer::timeout, &hans, &Hans::onTimeout);

    timer.start();

    return a.exec();
}

#include <QCoreApplication>
#include <QDebug>
#include "header.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Hans hans;
    qDebug() << hans.objectName() << "\n";

    return a.exec();
}

#include <QCoreApplication>
#include <QDebug>
#include "header.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // check the cmake output directory for a file
    // called moc_header.cpp
    Hans hans;
    qDebug() << hans.objectName() << "\n";

    return a.exec();
}

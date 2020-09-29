#include <QCoreApplication>
#include <QDebug>
#include "header.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Hans hans;

    // because of Q_OBJECT and Q_PROPERTIES we have additional functionality
    // normally you are not invoking those methods in cpp, however it may be
    // good practice for unit tests
    hans.setProperty("age", 3);
    qDebug() << hans.property("age").toInt();

    // normally you do this in cpp, using its declared getter and setter methods
    hans.setAge(2);
    qDebug() << hans.getAge();

    return a.exec();
}

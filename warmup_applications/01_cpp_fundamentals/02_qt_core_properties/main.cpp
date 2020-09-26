#include <QCoreApplication>
#include <QDebug>
#include "header.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Hans hans;

    // using declared getter and setter methods
    hans.setAge(2);
    qDebug() << hans.getAge();

    // wait because of Q_OBJECT and Q_PROPERTIES we have additional functionality
    hans.setProperty("age", 3);
    qDebug() << hans.property("age").toInt();

    return a.exec();
}

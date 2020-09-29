#include <QCoreApplication>
#include <QDebug>
#include "header.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person person;

    // example only shows you how qt does it internally, you do not have to do this later on!
    // however it may be a good practice for unit tests, change from directconnection to queuedconnection
    // what do you think happened?
    QString returnedValue;
    QMetaObject::invokeMethod(&person, "setName" , Qt::DirectConnection, Q_ARG(QString, "Hans"));
    QMetaObject::invokeMethod(&person, "setAge" , Qt::DirectConnection, Q_ARG(uint, 20));
    qDebug() << "name:" << person.getName();
    qDebug() << "age:" << person.getAge();


    // in cpp you invoke method typically via the function
    person.setName("Peter");
    person.setAge(50);
    qDebug() << "name:" << person.getName();
    qDebug() << "age:" << person.getAge();

    return a.exec();
}

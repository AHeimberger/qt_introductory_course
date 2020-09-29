#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "header.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Person person;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("cppPerson", &person);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

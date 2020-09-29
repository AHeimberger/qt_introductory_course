#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "header.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<Person>("PersonUri", 1, 0, "Person");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

#include "application.h"
#include <QGuiApplication>
#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "weather_controller.h"
#include "model_forecast.h"
#include "model_today.h"
#include "settings.h"

namespace Gui {

Application::Application() {
}

Application::~Application() {
}

int Application::start(int argc, char *argv[]) {
    qDebug() << "OpenWeatherMapp AppID:" << OPENWEATHERMAP_APPID;

    QGuiApplication app(argc, argv);
    QCoreApplication::setApplicationName("QtQuick Application");
    QCoreApplication::setApplicationVersion(OPENWEATHERMAP_LIBRARY_VERSION);

    WeatherController weather;
    weather.setAppId(OPENWEATHERMAP_APPID);
    weather.setLocation("Luzern");

    Settings settings;
    ModelToday modelToday;
    ModelForecast modelForecast;

    QObject::connect(&settings, &Settings::locationChanged, [&](){
        weather.setLocation(settings.getLocation());
        weather.requestCurrentWeatherByCityName();
    });
    QObject::connect(&weather, &WeatherController::weatherChanged, &modelToday, &ModelToday::onWeatherChanged, Qt::UniqueConnection);
    QObject::connect(&weather, &WeatherController::forecastChanged, &modelForecast, &ModelForecast::onForecastChanged, Qt::UniqueConnection);
    QObject::connect(&weather, &WeatherController::weatherChanged, [&](){
        weather.requestCurrentAndForecastWeatherData();
    });

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cppSettings", &settings);
    engine.rootContext()->setContextProperty("cppModelToday", &modelToday);
    engine.rootContext()->setContextProperty("cppModelForecast", &modelForecast);
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    settings.loadSettings();
    weather.requestCurrentWeatherByCityName();

    int status = app.exec();
    settings.storeSettings();
    return status;
}

} // namespace Gui

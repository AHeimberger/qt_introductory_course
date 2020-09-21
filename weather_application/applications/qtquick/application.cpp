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

    BusinessLogic::WeatherController weather;
    weather.setAppId(OPENWEATHERMAP_APPID);
    weather.setLocation("Luzern");

    BusinessLogic::Settings settings;
    BusinessLogic::ModelToday modelToday;
    BusinessLogic::ModelForecast modelForecast;

    QObject::connect(&settings, &BusinessLogic::Settings::locationChanged, [&](){
        weather.setLocation(settings.getLocation());
        weather.requestCurrentWeatherByCityName();
    });
    QObject::connect(&weather, &BusinessLogic::WeatherController::weatherChanged, &modelToday, &BusinessLogic::ModelToday::onWeatherChanged, Qt::UniqueConnection);
    QObject::connect(&weather, &BusinessLogic::WeatherController::forecastChanged, &modelForecast, &BusinessLogic::ModelForecast::onForecastChanged, Qt::UniqueConnection);
    QObject::connect(&weather, &BusinessLogic::WeatherController::weatherChanged, [&](){
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

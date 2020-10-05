#include "application.h"
#include <QGuiApplication>
#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
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

    QTranslator translator;
    if (translator.load("german_de.qm")) {
        qDebug() << "Translation loaded";
    }
    qApp->installTranslator(&translator);

    BusinessLogic::Settings settings;
    BusinessLogic::ModelToday modelToday;
    BusinessLogic::ModelForecast modelForecast;
    OpenWeatherMap::WeatherController weather;

    QObject::connect(&settings, &BusinessLogic::Settings::appIdChanged, [&](){
        weather.setAppId(settings.getAppId());
        weather.requestCurrentWeatherByCityName();
    });
    QObject::connect(&settings, &BusinessLogic::Settings::locationChanged, [&](){
        weather.setLocation(settings.getLocation());
        weather.requestCurrentWeatherByCityName();
    });
    QObject::connect(&settings, &BusinessLogic::Settings::languageChanged, [&](){
        weather.setLanguage(settings.getLanguage());
        weather.requestCurrentWeatherByCityName();
    });
    QObject::connect(&weather, &OpenWeatherMap::WeatherController::weatherChanged, &modelToday, &BusinessLogic::ModelToday::onWeatherChanged, Qt::UniqueConnection);
    QObject::connect(&weather, &OpenWeatherMap::WeatherController::forecastChanged, &modelForecast, &BusinessLogic::ModelForecast::onForecastChanged, Qt::UniqueConnection);
    QObject::connect(&weather, &OpenWeatherMap::WeatherController::weatherChanged, [&](){
        weather.requestCurrentAndForecastWeatherData();
    });

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cppSettings", &settings);
    engine.rootContext()->setContextProperty("cppModelToday", &modelToday);
    engine.rootContext()->setContextProperty("cppModelForecast", &modelForecast);
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    settings.loadSettings();
    weather.setAppId(settings.getAppId());
    weather.setLocation(settings.getLocation());
    weather.requestCurrentWeatherByCityName();

    int status = app.exec();
    settings.storeSettings();
    return status;
}

} // namespace Gui

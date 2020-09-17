#include <QCoreApplication>
#include <QCommandLineParser>
#include <QNetworkRequest>
#include <QDebug>
#include "requests.h"
#include "replies.h"
#include "weather_controller.h"


int main(int argc, char *argv[])
{
    qDebug() << "OpenWeatherMapp AppID:" << OPENWEATHERMAP_APPID;

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("CommandLine Application");
    QCoreApplication::setApplicationVersion(OPENWEATHERMAP_LIBRARY_VERSION);

    QString description;
    QCommandLineParser parser;
    parser.setApplicationDescription("This is a command line application for the openweathermap library.");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("city", "Requries the name of a city.");
    parser.addOption({ { "f", "forecast" }, "Add option if you want to sho forecast." });
    parser.process(app);

    QStringList positionalArguments = parser.positionalArguments();
    if (positionalArguments.isEmpty()) {
        parser.showHelp();
    }

    QString cityName = positionalArguments.first();
    bool isForecast = parser.isSet("forecast");

    WeatherController weather;
    weather.setAppId(OPENWEATHERMAP_APPID);
    weather.setLocation(cityName);

    QObject::connect(&weather, &WeatherController::weatherChanged, [&](const OpenWeatherMap::Replies::Data::CurrentWeather &weather){
        qDebug().noquote() << "Showing weather for:" << cityName;
        qDebug().noquote() << weather._timezone;
    });

    QObject::connect(&weather, &WeatherController::forecastChanged, [&](const OpenWeatherMap::Replies::Data::CurrentAndForecast &currentAndForecast){
        qDebug().noquote() << "Showing forecast for:" << cityName;
         qDebug().noquote() << currentAndForecast._daily.size();
    });

    if (isForecast) {
        weather.requestCurrentWeatherByCityName();
    }
    else {
        weather.requestCurrentWeatherByCityName();
    }

    return app.exec();
}

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QNetworkRequest>
#include <QDebug>
#include "requests.h"
#include "replies.h"
#include "weather_service.h"


int main(int argc, char *argv[])
{
    qDebug() << "OpenWeatherMapp AppID:" << OPENWEATHERMAP_APPID;

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("CommandLine Application");
    QCoreApplication::setApplicationVersion(OPENWEATHERMAP_LIBRARY_VERSION);

    QCommandLineParser parser;
    parser.setApplicationDescription("This is a command line application for the openweathermap library.");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("city", "Requires the name of a city.");
    parser.addOption({ { "f", "forecast" }, "Add option if you want to show forecast." });
    parser.process(app);

    QStringList positionalArguments = parser.positionalArguments();
    if (positionalArguments.isEmpty()) {
        parser.showHelp();
    }

    QString cityName = positionalArguments.first();
    bool isForecast = parser.isSet("forecast");

    OpenWeatherMap::WeatherService weather;
    weather.setAppId(OPENWEATHERMAP_APPID);
    weather.setLocation(cityName);

    QObject::connect(&weather, &OpenWeatherMap::WeatherService::weatherChanged, [&](const OpenWeatherMap::Replies::Data::CurrentWeather &weather){
        qDebug().noquote() << "Showing weather for:" << cityName;
        qDebug().noquote() << weather._time_zone;
    });

    QObject::connect(&weather, &OpenWeatherMap::WeatherService::forecastChanged, [&](const OpenWeatherMap::Replies::Data::CurrentAndForecast &currentAndForecast){
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

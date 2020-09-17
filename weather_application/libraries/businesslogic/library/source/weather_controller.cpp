#include "weather_controller.h"
#include <QMetaEnum>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


WeatherController::WeatherController() :
    _location(),
    _manager(new QNetworkAccessManager()) {
    QObject::connect(_manager, &QNetworkAccessManager::finished, this, &WeatherController::replyFinished);
}

WeatherController::~WeatherController() {
    delete _manager;
    _manager = nullptr;
}

void WeatherController::setAppId(const QString &appid) {
    if (_defaultQueryParams._app_id == appid)
        return;

    _defaultQueryParams._app_id = appid;
    emit appidChanged();
}

QString WeatherController::getAppId() const
{
    return _defaultQueryParams._app_id;
}

void WeatherController::setLocation(const QString &location) {
    if (_location == location)
        return;

    _location = location;
    emit locationChanged();
}

QString WeatherController::getLocation() const
{
    return _location;
}

void WeatherController::setLanguage(const QString &language)
{
    // todo (ahe) :: set language
}

void WeatherController::requestCurrentWeatherByCityName() {
    _reply_current_weather = _manager->get(OpenWeatherMap::Requests::currentWeatherByCityName(_defaultQueryParams, _location));
}

void WeatherController::requestCurrentAndForecastWeatherData() {
    _reply_current_and_forecast_weathers = _manager->get(
        OpenWeatherMap::Requests::currentAndForecastWeatherData(_defaultQueryParams,
                                                QString::number(_weather._coord._lat),
                                                QString::number(_weather._coord._lon))
        );
}

void WeatherController::replyFinished(QNetworkReply *reply) {
    if (!reply) {
        qDebug() << "Empty reply";
        return;
    }

    QByteArray byteArray = reply->readAll();
    // qDebug() << byteArray;

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error: " << reply->error() << ", " << byteArray;
        return;
    }

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (statusCode != 200) {
        qDebug() << "Status Code: " << statusCode << ", " << byteArray;
    }

    if (reply == _reply_current_weather)
    {
        _weather = OpenWeatherMap::Replies::currentWeather(byteArray);
        emit weatherChanged(_weather);
    }

    if (reply == _reply_current_and_forecast_weathers)
    {
        _weathers = OpenWeatherMap::Replies::currentAndForecast(byteArray);
        emit forecastChanged(_weathers);
    }
}

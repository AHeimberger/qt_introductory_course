#include "weather_controller.h"
#include <QMetaEnum>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace OpenWeatherMap {

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
}

void WeatherController::setLocation(const QString &location) {
    if (_location == location)
        return;

    _location = location;
}

void WeatherController::setLanguage(const QString &language)
{
    Enums::Languages languageEnum = Enums::getLanguageEnum(language);
    if (languageEnum == _defaultQueryParams._language)
        return;

    _defaultQueryParams._language = Enums::getLanguageEnum(language);
}

void WeatherController::requestCurrentWeatherByCityName() {
    _reply_current_weather = _manager->get(Requests::currentWeatherByCityName(_defaultQueryParams, _location));
}

void WeatherController::requestCurrentAndForecastWeatherData() {
    _reply_current_and_forecast_weathers = _manager->get(
        Requests::currentAndForecastWeatherData(_defaultQueryParams,
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
        _weather = Replies::currentWeather(byteArray);
        emit weatherChanged(_weather);
    }

    if (reply == _reply_current_and_forecast_weathers)
    {
        _weathers = Replies::currentAndForecast(byteArray);
        emit forecastChanged(_weathers);
    }

    reply->deleteLater();
}

} // namespace OpenWeatherMap

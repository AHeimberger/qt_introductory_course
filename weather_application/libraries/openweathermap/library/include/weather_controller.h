#ifndef WEATHER_CONTROLLER_H
#define WEATHER_CONTROLLER_H

#include "requests.h"
#include "replies.h"
#include <QVariantMap>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace OpenWeatherMap {

class WeatherController : public QObject {
    Q_OBJECT

signals:
    void weatherChanged(const OpenWeatherMap::Replies::Data::CurrentWeather &weather);
    void forecastChanged( const OpenWeatherMap::Replies::Data::CurrentAndForecast &weathers);

public:
    WeatherController();
    ~WeatherController();

    void setAppId(const QString &appid);
    void setLocation(const QString &location);
    void setLanguage(const QString &language);

    void requestCurrentWeatherByCityName();
    void requestCurrentAndForecastWeatherData();

private slots:
    void replyFinished(QNetworkReply *reply);

private:
    OpenWeatherMap::Requests::DefaultQueryParams _defaultQueryParams;
    QString _location = "";

    QNetworkAccessManager *_manager = nullptr;
    QNetworkReply* _reply_current_weather = nullptr;
    QNetworkReply* _reply_current_weathers = nullptr;
    QNetworkReply* _reply_current_and_forecast_weathers = nullptr;

    OpenWeatherMap::Replies::Data::CurrentWeather _weather;
    OpenWeatherMap::Replies::Data::CurrentAndForecast _weathers;
};

} // namespace OpenWeatherMap

#endif // WEATHER_CONTROLLER_H

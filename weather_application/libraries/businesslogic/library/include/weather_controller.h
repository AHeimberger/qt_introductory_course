#ifndef WEATHER_H
#define WEATHER_H

#include "requests.h"
#include "replies.h"
#include <QVariantMap>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WeatherController : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString appid READ getAppId WRITE setAppId NOTIFY appidChanged)
    Q_PROPERTY(QString location READ getLocation WRITE setLocation NOTIFY locationChanged)

signals:
    void appidChanged();
    void locationChanged();
    void weatherChanged(const OpenWeatherMap::Replies::Data::CurrentWeather &weather);
    void forecastChanged( const OpenWeatherMap::Replies::Data::CurrentAndForecast &weathers);

public:
    WeatherController();
    ~WeatherController();

    void setAppId(const QString &appid);
    QString getAppId() const;

    void setLocation(const QString &location);
    QString getLocation() const;

    void setLanguage(const QString &language);

    void requestCurrentWeatherByCityName();
    void requestCurrentAndForecastWeatherData();

private slots:
    void replyFinished(QNetworkReply *reply);

private:
    OpenWeatherMap::Requests::DefaultQueryParams _defaultQueryParams;
    QString _location;

    QNetworkAccessManager *_manager = nullptr;
    QNetworkReply* _reply_current_weather = nullptr;
    QNetworkReply* _reply_current_weathers = nullptr;
    QNetworkReply* _reply_current_and_forecast_weathers = nullptr;

    OpenWeatherMap::Replies::Data::CurrentWeather _weather;
    OpenWeatherMap::Replies::Data::CurrentAndForecast _weathers;
};

#endif // WEATHER_H

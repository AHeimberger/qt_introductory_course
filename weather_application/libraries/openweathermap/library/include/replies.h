#ifndef REPLIES_H
#define REPLIES_H

#include <QNetworkRequest>
#include <QByteArray>
#include <QObject>
#include <QDate>
#include <vector>

namespace OpenWeatherMap {

namespace Replies {

namespace Data {

struct CurrentWeather {
    typedef struct {
        double _lon;
        double _lat;
    } Coord;

    typedef struct {
        int _id;
        QString _main;
        QString _description;
        QString _icon;
    } Weather;

    typedef struct {
        double _temp;
        double _feels_like;
        double _temp_min;
        double _temp_max;
        double _pressure;
        double _humidity;
    } Main;

    typedef struct {
        double _speed;
        double _deg;
    } Wind;

    typedef struct {
        int _today;
    } Clouds;

    typedef struct {
        int _type;
        int _id;
        QString _country;
        QDateTime _sunrise;
        QDateTime _sunset;
    } Sys;

    Coord _coord;
    Weather _weather;
    QString _base;
    Main _main;
    Wind _wind;
    int _visibility;
    Clouds _clouds;
    QDateTime _dt;
    Sys _sys;
    int _time_zone;
    int _id;
    QString _name;
    int _cod;
};

struct CurrentAndForecast {
    typedef struct Daily {
        typedef struct {
            double _day;
            double _min;
            double _max;
            double _night;
            double _eve;
            double _morn;
        } Temp;

        typedef struct {
            double _day;
            double _night;
            double _eve;
            double _morn;
        } FeelsLike;

        typedef struct {
            int _id;
            QString _main;
            QString _description;
            QString _icon;
        } Weather;

        int _dt;
        int _sunrise;
        int _sunset;
        Temp _temp;
        FeelsLike _feels_like;
        int _pressure;
        int _humidity;
        double _dew_point;
        double _wind_speed;
        double _wind_deg;
        std::vector<Weather> _weather;
        int _clouds;
        double _pop;
        double _rain;
        double _uvi;
    } Daily;

    int _lat;
    int _lon;
    QString _time_zone;
    int _timezon_offset;
    // _current
    // _hourly
    std::vector<Daily> _daily;
};

} // namespace Data

Data::CurrentWeather currentWeather(const QByteArray &byte_array);

Data::CurrentAndForecast currentAndForecast(const QByteArray &byte_array);

} // namespace Replies

} // namespace OpenWeatherMap

#endif // REPLIES_H

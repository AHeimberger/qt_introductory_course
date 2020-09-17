#include "replies.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

namespace OpenWeatherMap {

namespace Replies {


Data::CurrentWeather currentWeather(const QByteArray &byte_array) {
    QJsonDocument json_doc = QJsonDocument::fromJson(byte_array);
    QJsonObject json_obj = json_doc.object();
    QDateTime dateTime;

    Data::CurrentWeather::Coord coord;
    coord._lat = json_obj["coord"].toObject()["lat"].toDouble();
    coord._lon = json_obj["coord"].toObject()["lon"].toDouble();

    Data::CurrentWeather::Weather weather;
    weather._id = json_obj["weather"].toArray()[0].toObject()["id"].toInt();
    weather._main = json_obj["weather"].toArray()[0].toObject()["main"].toString();
    weather._description = json_obj["weather"].toArray()[0].toObject()["description"].toString();
    weather._icon = json_obj["weather"].toArray()[0].toObject()["icon"].toString();

    Data::CurrentWeather::Main main;
    main._feels_like = json_obj["main"].toObject()["feels_like"].toDouble();
    main._humidity = json_obj["main"].toObject()["humidity"].toDouble();
    main._pressure = json_obj["main"].toObject()["pressure"].toDouble();
    main._temp = json_obj["main"].toObject()["temp"].toDouble();
    main._temp_max = json_obj["main"].toObject()["temp_max"].toDouble();
    main._temp_min = json_obj["main"].toObject()["temp_min"].toDouble();

    Data::CurrentWeather::Wind wind;
    wind._deg = json_obj["wind"].toObject()["deg"].toDouble();
    wind._speed = json_obj["wind"].toObject()["speed"].toDouble();

    Data::CurrentWeather::Clouds clouds;
    clouds._today = json_obj["clouds"].toObject()["today"].toInt();

    Data::CurrentWeather::Sys sys;
    sys._type = json_obj["sys"].toObject()["type"].toInt();
    sys._id = json_obj["sys"].toObject()["id"].toInt();
    sys._country = json_obj["sys"].toObject()["country"].toString();
    dateTime.setTime_t(json_obj["sys"].toObject()["sunrise"].toInt());
    sys._sunrise = dateTime;
    dateTime.setTime_t(json_obj["sys"].toObject()["sunset"].toInt());
    sys._sunset = dateTime;

    dateTime.setTime_t(json_obj["dt"].toInt());

    return Data::CurrentWeather {
        coord,
        weather,
        json_obj["base"].toString(),
        main,
        wind,
        json_obj["visibility"].toInt(),
        clouds,
        dateTime,
        sys,
        json_obj["timezone"].toInt(),
        json_obj["id"].toInt(),
        json_obj["name"].toString(),
        json_obj["cod"].toInt()
    };
}


Data::CurrentAndForecast currentAndForecast(const QByteArray &byte_array) {
    QJsonDocument json_doc = QJsonDocument::fromJson(byte_array);
    QJsonObject json_obj = json_doc.object();
    QJsonArray json_array = json_doc.object()["daily"].toArray();

    std::vector<Data::CurrentAndForecast::Daily> vector;
    for (auto entry: json_array) {
        QJsonObject obj = entry.toObject();

        Data::CurrentAndForecast::Daily::Temp temp {
            obj["temp"].toObject()["day"].toDouble(),
            obj["temp"].toObject()["min"].toDouble(),
            obj["temp"].toObject()["max"].toDouble(),
            obj["temp"].toObject()["night"].toDouble(),
            obj["temp"].toObject()["eve"].toDouble(),
            obj["temp"].toObject()["morn"].toDouble()
        };

        Data::CurrentAndForecast::Daily::FeelsLike feels_like {
            obj["feels_like"].toObject()["day"].toDouble(),
            obj["feels_like"].toObject()["night"].toDouble(),
            obj["feels_like"].toObject()["eve"].toDouble(),
            obj["feels_like"].toObject()["morn"].toDouble()
        };

        std::vector<Data::CurrentAndForecast::Daily::Weather> weathers;
        Data::CurrentAndForecast::Daily::Weather weather {
            obj["weather"].toArray()[0].toObject()["id"].toInt(),
            obj["weather"].toArray()[0].toObject()["main"].toString(),
            obj["weather"].toArray()[0].toObject()["description"].toString(),
            obj["weather"].toArray()[0].toObject()["icon"].toString()
        };
        weathers.push_back(weather);

            Data::CurrentAndForecast::Daily daily {
                obj["dt"].toInt(),
                obj["sunrise"].toInt(),
                obj["sunset"].toInt(),
                temp,
                feels_like,
                obj["pressure"].toInt(),
                obj["humidity"].toInt(),
                obj["dew_point"].toDouble(),
                obj["wind_speed"].toDouble(),
                obj["wind_deg"].toDouble(),
                weathers,
                obj["clouds"].toInt(),
                obj["pop"].toDouble(),
                obj["rain"].toDouble(),
                obj["uvi"].toDouble(),
                };
        vector.push_back(daily);
    }

    return Data::CurrentAndForecast {
        json_obj["lat"].toInt(),
        json_obj["lon"].toInt(),
        json_obj["timezone"].toString(),
        json_obj["timezone_offset"].toInt(),
        vector
    };
}


} // namespace Replies

} // namespace OpenWeatherMap

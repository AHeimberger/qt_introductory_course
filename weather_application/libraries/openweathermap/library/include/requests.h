#ifndef REQUESTS_H
#define REQUESTS_H

#include <QNetworkRequest>
#include <QByteArray>
#include <QObject>
#include <QDate>
#include <vector>

namespace OpenWeatherMap {

class Enums {
    Q_GADGET

public:
    enum Formats {
        json, xml, html
    };
    Q_ENUM(Formats)

    enum Units {
        fahrenheit, celcius, kelvin
    };
    Q_ENUM(Units)

    static QString getUnit(const Units &unit) {
        switch(unit) {
            case Units::fahrenheit: return "imperial";
            case Units::celcius: return "metric";
            case Units::kelvin: return "";
            default: return "metric";
        }
    }

    enum Languages {
        afrikaans, albanian, arabic, azerbaijani, bulgarian, catalan, czech, danish, german,
        greek, english, basque, persian, finnish, french, galician, hebrew, hindi, coration,
        hungarian, indonasian, italian, japanese, korean, latvian, lithuanian, macedonian,
        norwegian, dutch, polish, portuguese, portuguese_brazil, romanian, russian, swedish,
        slovak, slovenian, spanish, serbian, thai, turkish, urkainian, vietnamese, chinese_simplified,
        chinese_traditional, zulu
    };
    Q_ENUM(Languages)

    static QString getLanguageCode(const Languages &language) {
        // TODO (AHE): add other language codes

        switch(language) {
            case Languages::afrikaans: return "af";
            case Languages::albanian: return "al";
            case Languages::german: return "de";
            case Languages::english: return "en";
            default: return "";
        }
    }
};

namespace Requests {

typedef struct {
    QString _app_id = "";
    Enums::Formats _format = Enums::Formats::json;
    Enums::Units _units = Enums::Units::celcius;
    Enums::Languages _languages = Enums::Languages::english;
} DefaultQueryParams;

// Current Weather Data :: https://openweathermap.org/current

QNetworkRequest currentWeatherByCityName(const DefaultQueryParams &params,
                                         const QString &location,
                                         const QString &state_code="",
                                         const QString &country_code="");

QNetworkRequest currentWeatherByCityId(const DefaultQueryParams &params,
                                       const QString &city_id="");

QNetworkRequest currentWeatherByGeographicCoordinates(const DefaultQueryParams &params,
                                                      const QString &lat,
                                                      const QString &lon);

QNetworkRequest currentWeatherByZipCode(const DefaultQueryParams &params,
                                        const QString &zip_code,
                                        const QString &country_code="");

QNetworkRequest currentWeatherForCitiesWithinRectangleZone(const DefaultQueryParams &params,
                                                           const QString &lon_left,
                                                           const QString &lat_bottom,
                                                           const QString &lon_right,
                                                           const QString &lat_top,
                                                           const QString &zoom);

QNetworkRequest currentWeatherForCitiesInCircle(const DefaultQueryParams &params,
                                                const QString &lat,
                                                const QString &lon,
                                                const QString &cnt);

QNetworkRequest currentWeatherForCityIds(const DefaultQueryParams &params,
                                         const QStringList ids);

// Current and forecast weather data :: https://openweathermap.org/api/one-call-api

QNetworkRequest currentAndForecastWeatherData(const DefaultQueryParams &params,
                                              const QString &lat,
                                              const QString &lon,
                                              const QString &exclude="");

}; // namespace Requests

} // namespace OpenWeatherMap

#endif // REQUESTS_H

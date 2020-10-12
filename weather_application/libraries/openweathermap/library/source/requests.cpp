#include "requests.h"
#include <QMetaEnum>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QDebug>
#include <QMetaEnum>

namespace OpenWeatherMap {

const static QString BaseURI = "http://api.openweathermap.org";
// const static QString BaseURI = "http://localhost:8000";

const static QString Forecast16Days = "16";

QString Enums::getUnit(const Enums::Units &unit) {
    switch(unit) {
    case Units::fahrenheit: return "imperial";
    case Units::celcius: return "metric";
    case Units::kelvin: return "";
    default: return "metric";
    }
}

Enums::Languages Enums::getLanguageEnum(const QString &language) {
    bool isOk = true;
    QString languageCopy = language.toLower();
    auto&& metaEnum = QMetaEnum::fromType<Languages>();
    Languages languageEnum = static_cast<Languages>(metaEnum.keyToValue(languageCopy.toUtf8().data(), &isOk));

    if (isOk) {
        return languageEnum;
    }

    return Languages::english;
}

QString Enums::getLanguageCode(const Enums::Languages &language) {
    switch(language) {
    case Languages::albanian: return "al";
    case Languages::german: return "de";
    case Languages::english: return "en";
    case Languages::french: return "fr";
    default: return "en"; // use english as default
    }
}

namespace Requests {

void addQueryItems(const DefaultQueryParams &params, QUrl &uri, QUrlQuery items) {
    items.addQueryItem("appid", params._app_id);

    QMetaEnum metaEnum;
    metaEnum = QMetaEnum::fromType<Enums::Formats>();
    items.addQueryItem("mode", metaEnum.valueToKey(params._format));
    items.addQueryItem("units", Enums::getUnit(params._units));
    items.addQueryItem("lang", Enums::getLanguageCode(params._language));
    uri.setQuery(items);
}

QNetworkRequest createNetworkRequest(const QUrl &url) {
    QNetworkRequest req(url);
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    return req;
}

QNetworkRequest currentWeatherByCityName(const DefaultQueryParams &params,
                                         const QString &location,
                                         const QString &state_code,
                                         const QString &country_code) {
    QStringList list { location, state_code, country_code };
    list.removeAll({});
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/weather");
    addQueryItems(params, uri, {{ "q", list.join(",") }});
    return createNetworkRequest(uri);
}

QNetworkRequest currentWeatherByCityId(const DefaultQueryParams &params,
                                       const QString &city_id) {
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/weather");
    addQueryItems(params, uri, {{ "id", city_id }});
    return createNetworkRequest(uri);
}

QNetworkRequest currentWeatherByGeographicCoordinates(const DefaultQueryParams &params,
                                                      const QString &lat,
                                                      const QString &lon) {
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/weather");
    addQueryItems(params, uri, {{ "lat", lat }, {"lon", lon}});
    return createNetworkRequest(uri);
}

QNetworkRequest currentWeatherByZipCode(const DefaultQueryParams &params,
                                        const QString &zip_code,
                                        const QString &country_code) {
    QStringList list { zip_code, country_code };
    list.removeAll({});
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/weather");
    addQueryItems(params, uri, {{ "zip", list.join(",") }});
    return createNetworkRequest(uri);
}

QNetworkRequest currentWeatherForCitiesWithinRectangleZone(const DefaultQueryParams &params,
                                                           const QString &lon_left,
                                                           const QString &lat_bottom,
                                                           const QString &lon_right,
                                                           const QString &lat_top, const
                                                           QString &zoom) {
    QStringList list { lon_left, lat_bottom, lon_right, lat_top, zoom };
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/box/city");
    addQueryItems(params, uri, {{ "bbox", list.join(",") }});
    return createNetworkRequest(uri);
}

QNetworkRequest currentWeatherForCitiesInCircle(const DefaultQueryParams &params,
                                                const QString &lat,
                                                const QString &lon,
                                                const QString &cnt) {
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/find");
    addQueryItems(params, uri, {{ "lat", lat }, { "lon", lon }, { "cnt", cnt }});
    return createNetworkRequest(uri);
}

QNetworkRequest currentWeatherForCityIds(const DefaultQueryParams &params,
                                         const QStringList ids) {
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/group");
    addQueryItems(params, uri, {{ "id", ids.join(",") }});
    return createNetworkRequest(uri);
}

QNetworkRequest currentAndForecastWeatherData(const DefaultQueryParams &params,
                                              const QString &lat,
                                              const QString &lon,
                                              const QString &exclude) {
    QUrl uri(BaseURI);
    uri.setPath("/data/2.5/onecall");
    addQueryItems(params, uri, {{ "lat", lat }, {"lon", lon}, {"exclude", exclude}});
    return createNetworkRequest(uri);
}

} // namespace Requests

} // namespace MetaWeather

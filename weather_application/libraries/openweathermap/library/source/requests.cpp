#include "requests.h"
#include <QMetaEnum>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QDebug>

namespace OpenWeatherMap {

const static QString BaseURI = "http://api.openweathermap.org";

const static QString Forecast16Days = "16";

namespace Requests {

void addQueryItems(const DefaultQueryParams &params, QUrl &uri, QUrlQuery items) {
    items.addQueryItem("appid", params._app_id);

    QMetaEnum metaEnum;
    metaEnum = QMetaEnum::fromType<Enums::Formats>();
    items.addQueryItem("mode", metaEnum.valueToKey(params._format));
    items.addQueryItem("units", Enums::getUnit(params._units));
    items.addQueryItem("lang", Enums::getLanguageCode(params._languages));
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

#include "test_requests.h"
#include "requests.h"

TestRequests::TestRequests() {
    setObjectName("TestRequests");
}

void TestRequests::test_currentWeatherByCityName_expect_correct_url_with_default_params_empty_appid_json_metrics_de() {
    using namespace OpenWeatherMap::Requests;

    DefaultQueryParams queryParams;
    QNetworkRequest request = currentWeatherByCityName(queryParams, "zurich");

    QCOMPARE(request.url().toString(), "http://api.openweathermap.org/data/2.5/weather?q=zurich&appid=&mode=json&units=metric&lang=en");
}

void TestRequests::test_currentWeatherByCityName_expect_correct_url_with_filled_in_default_params() {
    using namespace OpenWeatherMap::Requests;

    DefaultQueryParams queryParams;
    queryParams._app_id = "myappid";
    queryParams._format = OpenWeatherMap::Enums::Formats::html;
    queryParams._units = OpenWeatherMap::Enums::Units::fahrenheit;
    queryParams._language = OpenWeatherMap::Enums::Languages::albanian;
    QNetworkRequest request = currentWeatherByCityName(queryParams, "Tirana");

    QCOMPARE(request.url().toString(), "http://api.openweathermap.org/data/2.5/weather?q=Tirana&appid=myappid&mode=html&units=imperial&lang=al");
}

void TestRequests::test_currentAndForecastWeatherData_expect_correct_url_with_default_params_appid_json_metrics_de() {
    using namespace OpenWeatherMap::Requests;

    DefaultQueryParams queryParams;
    queryParams._app_id = "myappid";
    QNetworkRequest request = currentAndForecastWeatherData(queryParams, "8.55", "47.37");

    QCOMPARE(request.url().toString(), "http://api.openweathermap.org/data/2.5/onecall?lat=8.55&lon=47.37&exclude=&appid=myappid&mode=json&units=metric&lang=en");
}

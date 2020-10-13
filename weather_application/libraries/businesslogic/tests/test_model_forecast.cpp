#include "test_model_forecast.h"
#include "model_forecast.h"

TestModelForecast::TestModelForecast() {
    setObjectName("TestModelForecast");
}

void TestModelForecast::values_are_empty_initialized_on_startup() {
    BusinessLogic::ModelForecast _testee;

    QCOMPARE(0, _testee.rowCount());
}

void TestModelForecast::on_forecasts_changed_values_are_initialized_and_signal_about_change_is_emitted() {
    using namespace OpenWeatherMap::Replies::Data;
    CurrentAndForecast data = create_test_data();

    BusinessLogic::ModelForecast _testee;
    _testee.onForecastChanged(data);

    QCOMPARE(_testee.rowCount(), 1);
    QCOMPARE(_testee.data(_testee.index(0), static_cast<int>(BusinessLogic::ModelForecast::Roles::Day)).toString(), "Thursday");
    QCOMPARE(_testee.data(_testee.index(0), static_cast<int>(BusinessLogic::ModelForecast::Roles::Icon)).toString(), "unknown");
    QCOMPARE(_testee.data(_testee.index(0), static_cast<int>(BusinessLogic::ModelForecast::Roles::TemperatureRange)).toString(), "0° / 0°");
}

OpenWeatherMap::Replies::Data::CurrentAndForecast TestModelForecast::create_test_data() {
    using namespace OpenWeatherMap::Replies::Data;

    CurrentAndForecast::Daily::Temp temp { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };
    CurrentAndForecast::Daily::FeelsLike feels_like { 0.1, 0.2, 0.3, 0.4 };
    std::vector<CurrentAndForecast::Daily::Weather> weathers;
    CurrentAndForecast::Daily::Weather weather { 1, "main", "description", "icon" };
    weathers.push_back(weather);

    CurrentAndForecast::Daily daily { 1, 2, 3, temp, feels_like, 4, 5, 0.1, 0.2, 0.3, weathers, 6, 0.4, 0.5, 0.6 };

    std::vector<CurrentAndForecast::Daily> vector;
    vector.push_back(daily);

    return CurrentAndForecast { 1, 2, "timezone", 3, vector };
}

#include "test_model_today.h"
#include "model_today.h"
#include "replies.h"
#include <QSignalSpy>

TestModelToday::TestModelToday() {
    setObjectName("TestModelToday");
}

void TestModelToday::test_values_are_empty_initialized_on_startup() {
    BusinessLogic::ModelToday _testee;

    QCOMPARE(_testee.property("city").toString(), "");
    QCOMPARE(_testee.property("description").toString(), "");
    QCOMPARE(_testee.property("icon").toString(), "unknown");
    QCOMPARE(_testee.property("temperature").toString(), "0°");
    QCOMPARE(_testee.property("date").toString(), "");
}

void TestModelToday::on_weather_changed_values_are_initialized_and_signal_about_change_is_emitted() {
    using namespace OpenWeatherMap::Replies::Data;
    CurrentWeather data = create_test_data();

    BusinessLogic::ModelToday _testee;
    _testee.onWeatherChanged(data);

    QCOMPARE(_testee.property("city").toString(), "name");
    QCOMPARE(_testee.property("description").toString(), "main");
    QCOMPARE(_testee.property("icon").toString(), "unknown");
    QCOMPARE(_testee.property("temperature").toString(), "0°");
    QCOMPARE(_testee.property("date").toString(), "Tue April 1912");
}

OpenWeatherMap::Replies::Data::CurrentWeather TestModelToday::create_test_data() {
    using namespace OpenWeatherMap::Replies::Data;

    QString string = "Tuesday, 23 April 12 22:51:41";
    QString format = "dddd, d MMMM yy hh:mm:ss";
    QDateTime dateTime = QDateTime::fromString(string, format);
    CurrentWeather::Coord coord {1, 2};
    CurrentWeather::Weather weather {1, "main", "description", "icon"};
    CurrentWeather::Main main { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };
    CurrentWeather::Wind wind { 0.1, 0.2 };
    CurrentWeather::Clouds clouds { 1 };
    CurrentWeather::Sys sys { 1, 2, "country", dateTime, dateTime };

    return CurrentWeather { coord, weather, "base", main, wind, 0, clouds, dateTime, sys, 1, 2, "name", 3 };
}

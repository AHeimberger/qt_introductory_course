#ifndef TEST_MODEL_TODAY_H
#define TEST_MODEL_TODAY_H

#include <QtTest>

namespace OpenWeatherMap::Replies::Data {
class CurrentWeather;
}

class TestModelToday: public QObject {
    Q_OBJECT

public:
    TestModelToday();

private slots:
    void test_values_are_empty_initialized_on_startup();
    void on_weather_changed_values_are_initialized_and_signal_about_change_is_emitted();

private:
    OpenWeatherMap::Replies::Data::CurrentWeather create_test_data();
};

#endif // TEST_MODEL_TODAY_H

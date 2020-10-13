#ifndef TEST_MODEL_FORECAST_H
#define TEST_MODEL_FORECAST_H

#include <QtTest>

namespace OpenWeatherMap::Replies::Data {
class CurrentAndForecast;
}

class TestModelForecast: public QObject {
    Q_OBJECT

public:
    TestModelForecast();

private slots:
    void values_are_empty_initialized_on_startup();
    void on_forecasts_changed_values_are_initialized_and_signal_about_change_is_emitted();

private:
    OpenWeatherMap::Replies::Data::CurrentAndForecast create_test_data();
};

#endif // TEST_MODEL_FORECAST_H

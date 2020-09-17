#ifndef TEST_REQUESTS_H
#define TEST_REQUESTS_H

#include <QtTest>

class TestRequests: public QObject {
    Q_OBJECT

public:
    TestRequests();

private slots:
    void test_currentWeatherByCityName_expect_correct_url_with_default_params_empty_appid_json_metrics_de();
    void test_currentWeatherByCityName_expect_correct_url_with_filled_in_default_params();
    void test_currentAndForecastWeatherData_expect_correct_url_with_default_params_appid_json_metrics_de();
};

#endif // TEST_REQUESTS_H

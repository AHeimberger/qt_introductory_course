#ifndef TEST_REPLIES_H
#define TEST_REPLIES_H

#include <QtTest>

class TestReplies: public QObject {
    Q_OBJECT

public:
    TestReplies();

private slots:
    void test_currentWeather_expect_correctly_filled_structure();
    void test_CurrentWeather_with_invalid_request_expect_invalid();
    void test_currentWeathers_expect_correctly_filled_structure();
};

#endif // TEST_REPLIES_H

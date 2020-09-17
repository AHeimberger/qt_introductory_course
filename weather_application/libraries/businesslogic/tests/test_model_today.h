#ifndef TEST_MODEL_TODAY_H
#define TEST_MODEL_TODAY_H

#include <QtTest>

class TestModelToday: public QObject {
    Q_OBJECT

public:
    TestModelToday();

private slots:
    void test_sample();
};

#endif // TEST_MODEL_TODAY_H

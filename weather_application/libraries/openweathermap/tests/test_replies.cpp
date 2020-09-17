#include "test_replies.h"
#include "replies.h"
#include <QDateTime>
#include <QDebug>
#include <QUrl>

QByteArray readFileContent(const QString &absoluteFilePath) {
    QFile file(absoluteFilePath);

    if (!file.exists()) {
        qWarning() << "Tried opening file" << absoluteFilePath << ". File not existing.";
        return QByteArray();
    }

    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "Tried opening file" << absoluteFilePath << ". File can not be opened.";
        return QByteArray();
    }

    QByteArray fileContent = file.readAll();
    file.close();

    return fileContent;
}

TestReplies::TestReplies() {
    setObjectName("TestReplies");
}

void TestReplies::test_currentWeather_expect_correctly_filled_structure() {
    QByteArray byteArray = readFileContent(":/day.json");
    OpenWeatherMap::Replies::Data::CurrentWeather testee = OpenWeatherMap::Replies::currentWeather(byteArray);

    QCOMPARE(testee._coord._lon, 8.31);
    QCOMPARE(testee._coord._lat, 47.05);
    QCOMPARE(testee._weather._id, 802);
    QCOMPARE(testee._weather._main, "Clouds");
    QCOMPARE(testee._weather._description, "scattered clouds");
    QCOMPARE(testee._weather._icon, "03n");
    QCOMPARE(testee._base, "stations");
    QCOMPARE(testee._main._temp, 19.92);
    QCOMPARE(testee._main._feels_like, 20.77);
    QCOMPARE(testee._main._temp_min, 19);
    QCOMPARE(testee._main._temp_max, 21);
    QCOMPARE(testee._main._pressure, 1021);
    QCOMPARE(testee._main._humidity, 77);
    QCOMPARE(testee._wind._speed, 1.5);
    QCOMPARE(testee._wind._deg, 20);
    QCOMPARE(testee._visibility, 10000);
    QCOMPARE(testee._clouds._today, 0);
    QCOMPARE(testee._dt, QDateTime::fromString("2020/09/18T00:10:58.000", Qt::ISODate));
    QCOMPARE(testee._sys._type, 1);
    QCOMPARE(testee._sys._id, 6933);
    QCOMPARE(testee._sys._country, "CH");
    QCOMPARE(testee._sys._sunrise, QDateTime::fromString("2020/09/18T07:08:41.000", Qt::ISODate));
    QCOMPARE(testee._sys._sunset, QDateTime::fromString("2020/09/18T19:33:04.000", Qt::ISODate));
    QCOMPARE(testee._timezone, 7200);
    QCOMPARE(testee._id, 2659811);
    QCOMPARE(testee._name, "Lucerne");
    QCOMPARE(testee._cod, 200);
}

void TestReplies::test_CurrentWeather_with_invalid_request_expect_invalid() {
    QByteArray byteArray = readFileContent(":/invalid_appid.json");
    OpenWeatherMap::Replies::Data::CurrentWeather testee = OpenWeatherMap::Replies::currentWeather(byteArray);

    // TODO
}

void TestReplies::test_currentWeathers_expect_correctly_filled_structure() {
    QByteArray byteArray = readFileContent(":/forecast.json");
    OpenWeatherMap::Replies::Data::CurrentAndForecast testee = OpenWeatherMap::Replies::currentAndForecast(byteArray);

    QCOMPARE(testee._lat, 0);
    QCOMPARE(testee._lon, 0);
    QCOMPARE(testee._timezone, "Etc/GMT");
    QCOMPARE(testee._timezon_offset, 0);
    QCOMPARE(testee._daily.size(), 8);
}

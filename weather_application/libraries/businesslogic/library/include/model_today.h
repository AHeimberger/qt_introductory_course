#ifndef MODEL_TODAY_H
#define MODEL_TODAY_H

#include <QObject>
#include "replies.h"

namespace BusinessLogic {

class ModelToday : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString city READ getCity NOTIFY weatherChanged)
    Q_PROPERTY(QString description READ getDescription NOTIFY weatherChanged)
    Q_PROPERTY(QString icon READ getIcon NOTIFY weatherChanged)
    Q_PROPERTY(QString temperature READ getTemperature NOTIFY weatherChanged)

public:
    ModelToday();
    ~ModelToday() = default;

    QString getCity();
    QString getDescription();
    QString getIcon();
    QString getTemperature();

signals:
    void weatherChanged();

public slots:
    void onWeatherChanged(const OpenWeatherMap::Replies::Data::CurrentWeather &currentWeather);

private:
    OpenWeatherMap::Replies::Data::CurrentWeather _currentWeather;
};

} // namespace BusinessLogic

#endif // MODEL_TODAY_H

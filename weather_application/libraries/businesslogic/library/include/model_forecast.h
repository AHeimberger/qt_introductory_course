#ifndef MODEL_FORECAST_H
#define MODEL_FORECAST_H

#include <QAbstractListModel>
#include "replies.h"

class ModelForecast: public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles { Day = (Qt::UserRole + 1), Icon, TemperatureRange };
    Q_ENUM(Roles)

    ModelForecast();
    virtual ~ModelForecast() = default;

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override final;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

public slots:
    void onForecastChanged(const OpenWeatherMap::Replies::Data::CurrentAndForecast &currentWeathers);

private:
    OpenWeatherMap::Replies::Data::CurrentAndForecast _currentForecast;
};

#endif // MODEL_FORECAST_H

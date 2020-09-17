#include "model_forecast.h"
#include "icon_mappings.h"
#include <QLocale>
#include <QDebug>

ModelForecast::ModelForecast(){
}

int ModelForecast::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)

    return _currentForecast._daily.size();
}

QVariant ModelForecast::data(const QModelIndex &index, int role) const {
    uint row = index.row();
    if (!index.isValid()) {
        qDebug() << row << " " << index.column();
        return false;
    }

    if (row > _currentForecast._daily.size())
        return QVariant();

    const auto& day = _currentForecast._daily[index.row()];
    switch (role) {
        case Day: {
            QLocale locale;
            QDateTime dateTime;
            dateTime.setSecsSinceEpoch(day._dt);
            return locale.dayName(dateTime.date().dayOfWeek());
        }

        case Icon:
            return getNameFromIconToken(day._weather.at(0)._icon);

        case TemperatureRange:
            return QString("%1° / %2°").arg(day._temp._min, 0, 'f', 0, 0).arg(day._temp._max, 0, 'f', 0, 0);

        default:
            return "";
    }
}

QHash<int, QByteArray> ModelForecast::roleNames() const {
    auto roles = QAbstractListModel::roleNames();
    roles.insert(Day, "day");
    roles.insert(Icon, "icon");
    roles.insert(TemperatureRange, "temperatureRange");
    return roles;
}

void ModelForecast::onForecastChanged(const OpenWeatherMap::Replies::Data::CurrentAndForecast &currentForecast) {
    // todo: works for qtquick
    beginResetModel();
    _currentForecast = currentForecast;
    endResetModel();

    // todo: works for qtwidget, because contains 4 static elements
    _currentForecast = currentForecast;
    auto topLeft = createIndex(0, 0);
    auto bottomRight = createIndex(_currentForecast._daily.size(), 1);
    emit dataChanged(topLeft, bottomRight);
}

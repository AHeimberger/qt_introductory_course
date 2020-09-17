#include "model_today.h"
#include "icon_mappings.h"

ModelToday::ModelToday()
{

}

QString ModelToday::getCity(){
    return _currentWeather._name;
}

QString ModelToday::getDescription(){
    return _currentWeather._weather._main;
}

QString ModelToday::getIcon(){
    return getNameFromIconToken(_currentWeather._weather._icon);
}

QString ModelToday::getTemperature(){
    return QString("%1°").arg(_currentWeather._main._temp, 0, 'f', 0, 0);
}

void ModelToday::onWeatherChanged(const OpenWeatherMap::Replies::Data::CurrentWeather &currentWeather) {
    _currentWeather = currentWeather;
    emit weatherChanged();
}

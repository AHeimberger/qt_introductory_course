#include "model_today.h"
#include "icon_mappings.h"

namespace BusinessLogic {

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
    return OpenWeatherMap::getNameFromIconToken(_currentWeather._weather._icon);
}

QString ModelToday::getTemperature(){
    return QString("%1°").arg(_currentWeather._main._temp, 0, 'f', 0, 0);
}

QString ModelToday::getDate(){
    return _currentWeather._dt.toString("ddd MMMM yyyy");
}

void ModelToday::onWeatherChanged(const OpenWeatherMap::Replies::Data::CurrentWeather &currentWeather) {
    _currentWeather = currentWeather;
    emit weatherChanged();
}

} // namespace BusinessLogic

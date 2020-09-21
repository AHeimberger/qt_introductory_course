#include "settings.h"
#include <QCoreApplication>
#include <QSettings>

namespace BusinessLogic {

Settings::Settings() :
    _settings_file(QCoreApplication::applicationDirPath() + "/settings.ini")
{
}

void Settings::setAppId(const QString &appId) {
    if (appId == _appId)
        return;

    _appId = appId;
    emit appIdChanged();
}

QString Settings::getAppId() const {
    return _appId;
}

void Settings::setLocationsAsList(const QStringList &locations) {
    if (locations == _locations)
        return;

    _locations = locations;
    emit locationsChanged();
}

QStringList Settings::getLocationsAsList() const {
    return _locations;
}

void Settings::setLocations(const QString &locations) {
    QStringList locationsList = locations.split("\n");
    locationsList.removeDuplicates();
    locationsList.removeAll(QStringLiteral(""));

    if (locationsList == _locations)
        return;

    _locations = locationsList;
    emit locationsChanged();
}

QString Settings::getLocations() const {
    return _locations.join("\n");
}

void Settings::setLocation(const QString &location) {
    if (location == _location)
        return;

    _location = location;
    emit locationChanged();
}

QString Settings::getLocation() const {
    return _location;
}

QStringList Settings::getLanguagesAsList() const {
    return {"English", "German", "French"};
}

void Settings::setLanguage(const QString &language) {
    if (language == _language)
        return;

    _language = language;
    emit languageChanged();
}

QString Settings::getLanguage() const {
    return _language;
}

void Settings::loadSettings() {
    QSettings settings(_settings_file, QSettings::NativeFormat);

    _appId = settings.value("appid", OPENWEATHERMAP_APPID).toString();
    emit appIdChanged();

    _locations = settings.value("locations", QStringList({"Zurich","New York","Sydney", "Tokyo", "Cape Town"})).toStringList();
    emit locationsChanged();

    _location = settings.value("location").toString();
    if (_location.isEmpty()) {
        _location = _locations.first();
    }
    emit locationChanged();

    _language = settings.value("language", "English").toString();
    emit languageChanged();
}

void Settings::storeSettings() {
    QSettings settings(_settings_file, QSettings::NativeFormat);

    settings.setValue("appid", _appId);
    settings.setValue("locations", _locations);
    settings.setValue("location",  _location);
    settings.setValue("language", _language);

    settings.sync();
}

} // namespace BusinessLogic

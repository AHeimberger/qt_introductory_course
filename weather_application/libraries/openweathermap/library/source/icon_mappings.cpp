#include "icon_mappings.h"
#include <QMap>

namespace OpenWeatherMap {

QMap<QString, QString> iconTokensToIconName {
    {"unknown", "unknown"},
    {"01d", "sunny"},
    {"01n", "sunny"},
    {"02d", "sunny-very-few-clouds"},
    {"02n", "sunny-very-few-clouds"},
    {"03d", "few-clouds"},
    {"03n", "few-clouds"},
    {"04d", "overcast"},
    {"04n", "overcast"},
    {"09d", "showers"},
    {"09n", "showers"},
    {"10d", "thundershower"},
    {"10n", "thundershower"},
    {"13d", "snow"},
    {"13n", "snow"},
    {"50d", "fog"},
    {"50n", "fog"}
};

QString getNameFromIconToken(const QString &iconToken) {
    if (iconTokensToIconName.contains(iconToken))
        return iconTokensToIconName[iconToken];

    return iconTokensToIconName["unknown"];
}

} // namespace OpenWeatherMap

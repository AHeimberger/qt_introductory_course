#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>
#include <QStringListModel>

namespace BusinessLogic {

class Settings: public QObject
{
    Q_OBJECT

public:
    Settings();

    Q_PROPERTY (QStringList locationsAsList READ getLocationsAsList WRITE setLocationsAsList NOTIFY locationsChanged)
    Q_PROPERTY (QString locations READ getLocations WRITE setLocations NOTIFY locationsChanged)
    Q_PROPERTY (QString location READ getLocation WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY (QStringList languagesAsList READ getLanguagesAsList CONSTANT)
    Q_PROPERTY (QString language READ getLanguage WRITE setLanguage NOTIFY languageChanged)

    void setLocationsAsList(const QStringList &locations);
    QStringList getLocationsAsList() const;

    void setLocations(const QString &locations);
    QString getLocations() const;

    void setLocation(const QString &location);
    QString getLocation() const;

    QStringList getLanguagesAsList() const;

    void setLanguage(const QString &language);
    QString getLanguage() const;

    void loadSettings();
    void storeSettings();

signals:
    void locationsChanged();
    void locationChanged();
    void languageChanged();

private:
    QString _settings_file;
    QStringList _locations;
    QString _location;
    QString _language;
};

} // namespace BusinessLogic

#endif // SETTINGS_H

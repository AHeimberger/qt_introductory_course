#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class WidgetContent;
class WidgetSettings;
class QTranslator;
class QStringListModel;
namespace BusinessLogic {
    class Settings;
    class ModelToday;
    class ModelForecast;
}
namespace OpenWeatherMap {
class WeatherService;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() final;

    void setLanguage(const QString& language);
    void setLocationStringModel(const QStringList& locationList);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void showSettingsDialog();

private:
    WidgetContent* _content_widget = nullptr;
    WidgetSettings* _settings_dialog = nullptr;
    QTranslator* _translator = nullptr;
    QStringListModel* _location_list_model = nullptr;
    QString _settings_file;
    QString _language;
    BusinessLogic::Settings *_settings = nullptr;
    OpenWeatherMap::WeatherService *_weather_service = nullptr;
    BusinessLogic::ModelToday *_model_today = nullptr;
    BusinessLogic::ModelForecast *_model_forecast = nullptr;
};

#endif // MAINWINDOW_H

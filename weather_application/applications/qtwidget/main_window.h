#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class WidgetContent;
class WidgetSettings;
class QTranslator;
class Settings;
class WeatherController;
class ModelToday;
class ModelForecast;
class QStringListModel;


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
    Settings *_settings = nullptr;
    WidgetContent* _content_widget = nullptr;
    WidgetSettings* _settings_dialog = nullptr;
    QTranslator* _translator = nullptr;
    WeatherController* _weather_controller = nullptr;
    ModelToday* _model_today = nullptr;
    ModelForecast* _model_forecast = nullptr;
    QStringListModel* _location_list_model = nullptr;
    QString _settings_file;
    QString _language;
};

#endif // MAINWINDOW_H

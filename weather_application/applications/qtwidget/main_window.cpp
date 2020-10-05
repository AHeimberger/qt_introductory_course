#include <QApplication>
#include <QDebug>
#include <QPalette>
#include <QResizeEvent>
#include <QSettings>
#include <QSize>
#include <QStringListModel>
#include <QTranslator>
#include "settings.h"
#include "weather_controller.h"
#include "model_today.h"
#include "model_forecast.h"
#include "widget_content.h"
#include "main_window.h"
#include "widget_settings.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    _settings_file(QApplication::applicationDirPath() + "/settings.ini")
{
    _settings = new BusinessLogic::Settings();
    _weather_controller = new OpenWeatherMap::WeatherController();
    _model_today = new BusinessLogic::ModelToday();
    _model_forecast = new BusinessLogic::ModelForecast();
    _location_list_model = new QStringListModel();
    _content_widget = new WidgetContent(this);
    _settings_dialog = new WidgetSettings(this);

    this->setCentralWidget(_content_widget);

    _content_widget->setModel(_location_list_model);
    _content_widget->setModel(_model_today);
    _content_widget->setModel(_model_forecast);

    _weather_controller->setAppId(OPENWEATHERMAP_APPID);
    _weather_controller->setLocation("Luzern");

    // widget
    QObject::connect(_content_widget, &WidgetContent::locationChanged, _settings, &BusinessLogic::Settings::setLocation, Qt::UniqueConnection);
    QObject::connect(_content_widget, &WidgetContent::showSettingsDialog, this, &MainWindow::showSettingsDialog, Qt::UniqueConnection);
    QObject::connect(_settings, &BusinessLogic::Settings::locationChanged, [&](){
        _weather_controller->setLocation(_settings->getLocation());
        _weather_controller->requestCurrentWeatherByCityName();
    });

    // controller
    QObject::connect(_weather_controller, &OpenWeatherMap::WeatherController::weatherChanged, _model_today, &BusinessLogic::ModelToday::onWeatherChanged, Qt::UniqueConnection);
    QObject::connect(_weather_controller, &OpenWeatherMap::WeatherController::forecastChanged, _model_forecast, &BusinessLogic::ModelForecast::onForecastChanged, Qt::UniqueConnection);
    QObject::connect(_weather_controller, &OpenWeatherMap::WeatherController::weatherChanged, [&](){
        _weather_controller->requestCurrentAndForecastWeatherData();
    });

    _settings->loadSettings();
    _weather_controller->requestCurrentWeatherByCityName();
    _location_list_model->setStringList(_settings->getLocationsAsList());
}

MainWindow::~MainWindow()
{
    _settings->storeSettings();
}

void MainWindow::setLanguage(const QString& language)
{
    _settings->setLanguage(language);
    auto newTranslate = new QTranslator(this);

    if (!newTranslate->load("WeatherWidgetLib_" + language + ".qm", "../WeatherWidgetLib/translations")) {
        return;
    }

    // _weather_controller->setLanguage(language);
    if( QCoreApplication::installTranslator(newTranslate) == false ) {
        qDebug() << "Installing of the new translator " << language << " failed!";
    }

    if (_translator) {
        QCoreApplication::removeTranslator(_translator);
        delete _translator;
    }

    _translator = newTranslate;
}

void MainWindow::setLocationStringModel(const QStringList &locationList)
{
    if(locationList.size() > 0)
    {
        _location_list_model->setStringList(locationList);
        _weather_controller->setLocation(_settings->getLocation());
        _weather_controller->requestCurrentWeatherByCityName();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    _settings_dialog->setGeometry(event->size().width(), 0, event->size().width(), event->size().height());

    QMainWindow::resizeEvent(event);
}

void MainWindow::showSettingsDialog()
{
    _settings_dialog->move(this->x()+this->width(), this->y()+this->height() - _settings_dialog->height());

    _settings_dialog->setLanguages(QStringList({"en", "de", "fr"}));
    _settings_dialog->setCurrentLanguage(_language);
    _settings_dialog->setLocations(_location_list_model->stringList());

    _settings_dialog->startAnimation();
}

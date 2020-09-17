#ifndef WIDGETCONTENT_H
#define WIDGETCONTENT_H

#include <QMap>
#include <QPixmap>
#include <QWidget>

class QComboBox;
class QDataWidgetMapper;
class QPushButton;
class QStringListModel;
class QListView;
class WidgetToday;
class ModelToday;
class ModelForecast;
class WidgetForecastItem;


class WidgetContent : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetContent(QWidget *parent = nullptr);

    void setModel(ModelToday* model);
    void setModel(ModelForecast *model);
    void setModel(QStringListModel* model);

protected:
    void paintEvent(QPaintEvent *) override;

signals:
    void requestWeather();
    void locationChanged(const QString& city);
    void showSettingsDialog();

public slots:
    void selectionChanged(const QString& selected_city);

protected:
     void mousePressEvent(QMouseEvent* event) override;
     void changeEvent(QEvent *event) override;

private:
    static const int FORECAST_ITEM_COUNT = 4;

    QComboBox* _combobox_location = nullptr;
    WidgetToday* _today_widget = nullptr;
    QDataWidgetMapper* dataMapper = nullptr;
    QPushButton* _button_settings = nullptr;
    QListView *forecastView = nullptr;
    WidgetForecastItem* _items_forecast[FORECAST_ITEM_COUNT];
};

#endif // WIDGETCONTENT_H

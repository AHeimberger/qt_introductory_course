#ifndef WIDGETFORECASTITEM_H
#define WIDGETFORECASTITEM_H

#include <QWidget>

class QLabel;
class LabelAspectRatio;
class WeatherForecastModel;
namespace BusinessLogic {
class ModelForecast;
}

class WidgetForecastItem : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetForecastItem(QWidget *parent = nullptr);

    void setModel(BusinessLogic::ModelForecast *model, int row);

protected:
    void paintEvent(QPaintEvent *) override;

protected slots:
    void updateFields();

private:
    QLabel* dayLabel = nullptr;
    LabelAspectRatio* weatherIcon = nullptr;
    QLabel* temperature = nullptr;
    BusinessLogic::ModelForecast *_model = nullptr;
    int _row = -1;
};

#endif // WIDGETFORECASTITEM_H

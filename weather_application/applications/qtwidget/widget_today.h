#ifndef WIDGETTODAY_H
#define WIDGETTODAY_H

#include <QWidget>

class QLabel;
class LabelAspectRatio;
class ModelToday;

class WidgetToday : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetToday(QWidget *parent = nullptr);
    void setModel(ModelToday* model);

protected:
    void paintEvent(QPaintEvent *) override;

protected slots:
    void updateFields();

private:
    ModelToday *_model = nullptr;
    QLabel* _temperature_text = nullptr;
    LabelAspectRatio* _weather_icon = nullptr;
    QLabel* _weather_text = nullptr;
};

#endif // WIDGETTODAY_H

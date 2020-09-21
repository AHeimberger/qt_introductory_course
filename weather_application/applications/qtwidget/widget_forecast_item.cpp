#include "widget_forecast_item.h"
#include "label_aspect_ratio.h"
#include "model_forecast.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QStyleOption>
#include <QDataWidgetMapper>
#include <QSvgRenderer>

WidgetForecastItem::WidgetForecastItem(QWidget *parent)
    : QWidget(parent)
{
#ifdef GRAPHICAL_DEBUG
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(background);
#endif

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setContentsMargins(0, 0, 0, 0);
    vlayout->setSpacing(10);

    _weather_icon = new LabelAspectRatio(this);
    _weather_icon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    _weather_icon->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    _weather_icon->setMinimumSize(QSize(40, 40));
    _weather_icon->setScaledContents(true);

    _day_label = new QLabel(this);
    _day_label->setObjectName("ForecastDayLabel");
    _day_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    _temperature = new QLabel(this);
    _temperature->setObjectName("ForecastTemperatureLabel");
    _temperature->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    vlayout->addWidget(_day_label);
    vlayout->addWidget(_weather_icon, 1);
    vlayout->addWidget(_temperature);

    setLayout(vlayout);
}

void WidgetForecastItem::setModel(BusinessLogic::ModelForecast *model, int row)
{
    _model = model;
    _row = row;

    QObject::connect(model, &BusinessLogic::ModelForecast::dataChanged, this, &WidgetForecastItem::updateFields, Qt::UniqueConnection);

    updateFields();
}

void WidgetForecastItem::updateFields()
{
    QModelIndex index = _model->index(_row);
    if (!index.isValid())
        return;

    _temperature->setText(_model->data(index, BusinessLogic::ModelForecast::Roles::TemperatureRange).value<QString>());

    QSvgRenderer renderer(QString(":/weather/%1.svg").arg(_model->data(index, BusinessLogic::ModelForecast::Roles::Icon).value<QString>()));
    QPixmap pm(100, 100);
    pm.fill(Qt::transparent);
    QPainter painter(&pm);
    renderer.render(&painter, pm.rect());
    _weather_icon->setPixmap(pm);

    _day_label->setText(_model->data(index, BusinessLogic::ModelForecast::Roles::Day).value<QString>());
}

void WidgetForecastItem::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

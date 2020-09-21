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

    weatherIcon = new LabelAspectRatio(this);
    weatherIcon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    weatherIcon->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    weatherIcon->setMinimumSize(QSize(40, 40));
    weatherIcon->setScaledContents(true);

    dayLabel = new QLabel(this);
    dayLabel->setObjectName("ForecastDayLabel");
    dayLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    temperature = new QLabel(this);
    temperature->setObjectName("ForecastTemperatureLabel");
    temperature->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    vlayout->addWidget(dayLabel);
    vlayout->addWidget(weatherIcon, 1);
    vlayout->addWidget(temperature);

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

    temperature->setText(_model->data(index, BusinessLogic::ModelForecast::Roles::TemperatureRange).value<QString>());

    QSvgRenderer renderer(QString(":/weather/%1.svg").arg(_model->data(index, BusinessLogic::ModelForecast::Roles::Icon).value<QString>()));
    QPixmap pm(100, 100);
    pm.fill(Qt::transparent);
    QPainter painter(&pm);
    renderer.render(&painter, pm.rect());
    weatherIcon->setPixmap(pm);

    dayLabel->setText(_model->data(index, BusinessLogic::ModelForecast::Roles::Day).value<QString>());
}

void WidgetForecastItem::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

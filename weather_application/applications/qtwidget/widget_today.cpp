#include <QDataWidgetMapper>
#include <QLabel>
#include <QPainter>
#include <QStyleOption>
#include <QVBoxLayout>
#include <QSvgRenderer>
#include "model_today.h"
#include "label_aspect_ratio.h"
#include "widget_today.h"


WidgetToday::WidgetToday(QWidget *parent)
    : QWidget(parent)
{
#ifdef GRAPHICAL_DEBUG
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::blue);
    this->setAutoFillBackground(true);
    this->setPalette(background);
#endif

    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);

    _temperature_text = new QLabel(this);
    _temperature_text->setObjectName("temperature");
    _temperature_text->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    _temperature_text->setMinimumHeight(50);

    _weather_icon = new LabelAspectRatio(this);
    _weather_icon->setObjectName("weatherIcon");
    _weather_icon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    _weather_icon->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    _weather_icon->setMinimumSize(QSize(40, 40));
    _weather_icon->setScaledContents(true);

    _weather_text = new QLabel(this);
    _weather_text->setObjectName("weather");
    _weather_text->setAlignment(Qt::AlignRight | Qt::AlignBottom);

    //vLayout->addWidget(_temperature_text, 0);
    vLayout->addWidget(_weather_icon, 10);
    vLayout->addWidget(_weather_text, 0);

    vLayout->addStretch(1);

    setLayout(vLayout);
}


void WidgetToday::setModel(ModelToday *model)
{
    _model = model;

    QObject::connect(model, &ModelToday::weatherChanged, this, &WidgetToday::updateFields, Qt::UniqueConnection);

    updateFields();
}

void WidgetToday::updateFields()
{
    _temperature_text->setText(_model->getTemperature());

    QSvgRenderer renderer(QString(":/weather/%1.svg").arg(_model->getIcon()));
    QPixmap pm(400, 400);
    pm.fill(Qt::transparent);
    QPainter painter(&pm);
    renderer.render(&painter, pm.rect());
    _weather_icon->setPixmap(pm);

    _weather_text->setText(_model->getDescription());
}

void WidgetToday::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

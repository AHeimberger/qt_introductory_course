#include "widget_content.h"
#include "widget_forecast_item.h"
#include "widget_today.h"
#include "model_today.h"
#include "model_forecast.h"

#include <QGridLayout>
#include <QComboBox>
#include <QScrollBar>
#include <QListView>
#include <QPixmap>
#include <QEvent>
#include <QPainter>
#include <QPushButton>
#include <QStringListModel>


WidgetContent::WidgetContent(QWidget *parent)
    : QWidget(parent)
{
#ifdef GRAPHICAL_DEBUG
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::green);
    this->setAutoFillBackground(true);
    this->setPalette(background);
#endif

    QGridLayout* layout_grid = new QGridLayout;

    _combobox_location = new QComboBox;

    _button_settings = new QPushButton(this);
    _button_settings->setObjectName("SettingsButton");
    _button_settings->setIcon(QPixmap(":/settings/menu.svg"));

    _today_widget = new WidgetToday(this);
    _today_widget->setObjectName("todayWidget");

    QHBoxLayout* layout_forecast = new QHBoxLayout;
    layout_forecast->setSpacing(8);
    for (int index = 0; index < FORECAST_ITEM_COUNT; ++index)
    {
        auto widget = new WidgetForecastItem(this);
        layout_forecast->addWidget(widget, 1);
        _items_forecast[index] = widget;
    }

    layout_grid->addWidget(_combobox_location, 0, 0, 1, 3);
    layout_grid->addWidget(_button_settings, 0, 3, 1, 1);
    layout_grid->addWidget(_today_widget, 1, 0, 1, 4);
    layout_grid->addLayout(layout_forecast, 2, 0, 1, 4);

    layout_grid->setRowStretch(0, 1);
    layout_grid->setRowStretch(1, 10);
    layout_grid->setRowStretch(2, 1);

    layout_grid->setRowMinimumHeight(2, 100);

    layout_grid->setSizeConstraint(QLayout::SetMaximumSize);

    setLayout(layout_grid);

    connect(_combobox_location, &QComboBox::currentTextChanged, this, &WidgetContent::selectionChanged, Qt::UniqueConnection);
    connect(_button_settings, &QPushButton::clicked, this, &WidgetContent::showSettingsDialog, Qt::UniqueConnection);
}

void WidgetContent::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void WidgetContent::selectionChanged(const QString& selected_city)
{
    emit locationChanged(selected_city);
}

void WidgetContent::setModel(ModelToday *model)
{
    _today_widget->setModel(model);
}

void WidgetContent::setModel(QStringListModel *model)
{
    _combobox_location->setModel(model);
}

void WidgetContent::setModel(ModelForecast *model)
{
    for (int index = 0; index < FORECAST_ITEM_COUNT; ++index) {
        _items_forecast[index]->setModel(model, index + 1);
    }
}

void WidgetContent::changeEvent(QEvent* event)
{
    if (event != nullptr)
    {
        switch(event->type())
        {
        case QEvent::LanguageChange:
            emit requestWeather();
            break;
        default:
            break;
        }
    }

    QWidget::changeEvent(event);
}

void WidgetContent::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
}

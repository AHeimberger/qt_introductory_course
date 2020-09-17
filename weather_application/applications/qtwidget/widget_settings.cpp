#include <QBoxLayout>
#include <QComboBox>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QLabel>
#include <QLocale>
#include <QPainter>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTimeLine>
#include <QTranslator>
#include "settings.h"
#include "main_window.h"
#include "widget_settings.h"

WidgetSettings::WidgetSettings(QWidget *parent)
    : QFrame(parent)
{
#ifdef GRAPHICAL_DEBUG
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::blue);
    this->setAutoFillBackground(true);
    this->setPalette(background);
#endif

    _static_test_location = new QLabel;
    _static_text_language = new QLabel;

    auto frame = new QFrame(this);
    _multi_line_city_edit = new QPlainTextEdit(frame);
    _language_combo_box = new QComboBox(frame);
    _button_okay = new QPushButton(frame);
    _button_cancel = new QPushButton(frame);

    frame->setObjectName("widgetSettings");
    _button_okay->setText(QCoreApplication::translate("Common","OK"));
    _button_cancel->setText(QCoreApplication::translate("Common","CANCEL"));
    _static_test_location->setText(QCoreApplication::translate("Settings","LOCATION")+":");
    _static_text_language->setText(QCoreApplication::translate("Settings","LANGUAGE")+":");

    auto layout_content = new QHBoxLayout;
    layout_content->setMargin(0);

    auto layout_vbox = new QVBoxLayout;
    layout_vbox->setMargin(0);

    auto layout_hbox = new QHBoxLayout;
    layout_hbox->setMargin(0);

    layout_hbox->addWidget(_button_okay);
    layout_hbox->addStretch(1);
    layout_hbox->addWidget(_button_cancel);

    layout_vbox->addWidget(_static_test_location);
    layout_vbox->addWidget(_multi_line_city_edit,  2);
    layout_vbox->addSpacing(10);
    layout_vbox->addWidget(_static_text_language);
    layout_vbox->addWidget(_language_combo_box);
    layout_vbox->addSpacing(10);
    layout_vbox->addLayout(layout_hbox);

    frame->setLayout(layout_vbox);

    layout_content->addWidget(frame);
    setLayout(layout_content);

    _time_line = new QTimeLine(400, this);
    _time_line->setDirection(QTimeLine::Forward);
    _time_line->setUpdateInterval(90);
    _time_line->setFrameRange(0, 100);
    _time_line->setEasingCurve(QEasingCurve::InCubic);


    connect(_button_okay, &QPushButton::clicked, this, &WidgetSettings::okayButtonClicked, Qt::UniqueConnection );
    connect(_button_cancel, &QPushButton::clicked, this, &WidgetSettings::cancelButtonClicked, Qt::UniqueConnection );
    connect(_language_combo_box, SIGNAL(currentIndexChanged(QString)), this, SLOT(languageChanged(QString)), Qt::UniqueConnection );
    connect(_time_line, &QTimeLine::valueChanged, this, &WidgetSettings::timeLineValueChanged, Qt::UniqueConnection );
    connect(_time_line, &QTimeLine::finished, this, &WidgetSettings::timeLineFinished, Qt::UniqueConnection );

}

QStringList WidgetSettings::locations() const
{
    return _multi_line_city_edit->toPlainText().split('\n', Qt::SkipEmptyParts);
}

void WidgetSettings::setLocations(const QStringList &list) {
    _multi_line_city_edit->setPlainText(list.join('\n'));
}

QString WidgetSettings::currentLanguage() const
{
    return _language_combo_box->currentText();
}

void WidgetSettings::setCurrentLanguage(const QString &language)
{
    _language_combo_box->setCurrentText(language);
}

void WidgetSettings::setLanguages(const QStringList &list)
{
    _language_combo_box->clear();
    _language_combo_box->addItems(list);
}

void WidgetSettings::startAnimation()
{
    if(_time_line->state() != QTimeLine::Running)
        _time_line->start();
}

void WidgetSettings::languageChanged(const QString &language)
{
    _tmp_translator = new QTranslator(this);

    if (!_tmp_translator->load("WeatherWidgetLib_" + language + ".qm", "../WeatherWidgetLib/translations"))
    {
        qDebug() << "Loading of the new translator " << language << " failed!";
        return;
    }

    if( QCoreApplication::installTranslator(_tmp_translator) == false )
    {
        qDebug() << "Installing of the new translator " << language << " failed!";
    }

    _button_okay->setText(QCoreApplication::translate("Common","OK"));
    _button_cancel->setText(QCoreApplication::translate("Common","CANCEL"));
    _static_test_location->setText(QCoreApplication::translate("Settings","LOCATION")+":");
    _static_text_language->setText(QCoreApplication::translate("Settings","LANGUAGE")+":");

    if (_tmp_translator)
    {
        QCoreApplication::removeTranslator(_tmp_translator);
        delete _tmp_translator;
        _tmp_translator = nullptr;
    }
}

void WidgetSettings::timeLineValueChanged(qreal value)
{
    int posX = (parentWidget()->width()) - static_cast<int>( static_cast<qreal>(parentWidget()->width())*value);
    move(posX, 0);
}

void WidgetSettings::timeLineFinished()
{
    if(_time_line->direction() == QTimeLine::Forward)
        _time_line->setDirection(QTimeLine::Backward);
    else
        _time_line->setDirection(QTimeLine::Forward);
}

void WidgetSettings::okayButtonClicked()
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());

    if(mainWindow)
    {
        mainWindow->setLanguage(currentLanguage());
        mainWindow->setLocationStringModel(this->locations());
    }

    startAnimation();
}

void WidgetSettings::cancelButtonClicked()
{
    startAnimation();
}

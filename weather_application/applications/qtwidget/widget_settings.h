#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QFrame>

class QComboBox;
class QLabel;
class QPlainTextEdit;
class QPushButton;
class QTimeLine;
class QTranslator;

class WidgetSettings : public QFrame
{
    Q_OBJECT

public:
    explicit WidgetSettings(QWidget *parent = nullptr);

public:
    QStringList locations() const;
    void setLocations(const QStringList& list);

    QString currentLanguage() const;
    void setCurrentLanguage(const QString& language);
    void setLanguages(const QStringList& list);

public slots:
    void startAnimation();

private slots:
    void languageChanged(const QString& language);
    void timeLineValueChanged(qreal value);
    void timeLineFinished();
    void okayButtonClicked();
    void cancelButtonClicked();

private:
    QPlainTextEdit* _multi_line_city_edit = nullptr;
    QComboBox* _language_combo_box = nullptr;
    QPushButton* _button_okay = nullptr;
    QPushButton* _button_cancel = nullptr;
    QLabel* _static_test_location = nullptr;
    QLabel* _static_text_language = nullptr;
    QTranslator* _tmp_translator = nullptr;
    QTimeLine* _time_line = nullptr;
};

#endif // WIDGETSETTINGS_H

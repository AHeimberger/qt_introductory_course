import QtQuick 2.0
import QtQuick.Layouts 1.0
import "."

ColumnLayout {
    id: viewWeather
    spacing: 0
    clip: true

    readonly property int max_visible_entries: 4

    signal settingsClicked

    SettingsMenu {
        Layout.fillWidth: true
        Layout.preferredHeight: 50
        onButtonClicked: viewWeather.settingsClicked()
    }

    Line {
        Layout.fillWidth: true
        Layout.preferredHeight: 1
    }

    TodayWeatherItem {
        Layout.fillHeight: true
        Layout.minimumHeight: 300
        Layout.fillWidth: true
        city: cppModelToday.city
        temperature: cppModelToday.temperature
        icon: "qrc:///weather/" + cppModelToday.icon + ".svg"
        description: cppModelToday.description
        date: cppModelToday.date
    }

    Line {
        Layout.fillWidth: true
        Layout.preferredHeight: 1
        color: Style.forecast_item.line_color
    }

    ListView {
        id: repeaterItem
        Layout.fillWidth: true
        Layout.preferredHeight: 100
        orientation: ListView.LeftToRight
        model: cppModelForecast

        delegate: Rectangle {
            width: (repeaterItem.width / max_visible_entries)
            height: repeaterItem.height
            color: Style.forecast_item.background_color

            Line {
                visible: (index !== 0)
                anchors.left: parent.left
                height: parent.height
                width: 1
                color: Style.forecast_item.line_color
            }

            ForecastWeatherItem {
                anchors.fill: parent
                anchors.topMargin: 5
                anchors.bottomMargin: 5
                temperatureRange: model.temperatureRange
                day: model.day
                icon: "qrc:///weather/" + model.icon + ".svg"
            }
        }
    }
}

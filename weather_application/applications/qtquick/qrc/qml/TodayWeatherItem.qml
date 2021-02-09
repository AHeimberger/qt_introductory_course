import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtGraphicalEffects 1.0
import "."

Rectangle {
    id: todayWeatherItem
    gradient: Gradient {
        GradientStop { position: 0.0; color: Style.today_item.gradient_start }
        GradientStop { position: 1.0; color: Style.today_item.gradient_stop }
    }

    property alias city: city.text
    property alias temperature: temperature.text
    property alias icon: icon.source
    property alias description: description.text
    property alias date: date.text

    GridLayout {
        id: weatherItem
        anchors.centerIn: parent
        columns: 2; columnSpacing: 0
        rows: 3; rowSpacing: 0

        Column {
            Text {
                id: description
                font.pointSize: 30
                anchors.right: parent.right
                horizontalAlignment: Text.AlignRight
                color: Style.today_item.font_color
            }

            Text {
                id: temperature
                font.pointSize: 50
                anchors.right: parent.right
                horizontalAlignment: Text.AlignRight
                color: Style.today_item.font_color
            }
        }

        Item {
            Layout.preferredWidth: 200
            Layout.preferredHeight: 200

            ScaledImage {
                id: icon
                anchors.centerIn: parent
                scaling: 7
                padding: 40
            }

            ColorOverlay{
                source: icon
                anchors.fill: icon
                antialiasing: true
                color: Style.today_item.icon_color
            }
        }

        Text {
            id: date
            font.pointSize: 20
            Layout.columnSpan: 2
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
            color: Style.today_item.font_color
        }

        Text {
            id: city
            font.pointSize: 40
            wrapMode: Text.WordWrap
            Layout.columnSpan: 2
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
            color: Style.today_item.font_color
        }
    }
}

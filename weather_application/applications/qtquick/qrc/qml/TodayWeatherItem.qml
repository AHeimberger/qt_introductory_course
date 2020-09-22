import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtGraphicalEffects 1.0

Rectangle {
    id: todayWeatherItem
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#FE8100" }
        GradientStop { position: 1.0; color: "#ff0000" }
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
        rows: 2; rowSpacing: 0

        Column {
            Text {
                id: description
                font.pointSize: 30
                anchors.right: parent.right
                horizontalAlignment: Text.AlignRight
                color: "white"
            }

            Text {
                id: temperature
                font.pointSize: 50
                color: "white"
                anchors.right: parent.right
                horizontalAlignment: Text.AlignRight
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
                color: "white"
            }
        }

        Text {
            id: date
            font.pointSize: 20
            color: "white"
            Layout.columnSpan: 2
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: city
            font.pointSize: 40
            wrapMode: Text.WordWrap
            color: "white"
            Layout.columnSpan: 2
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }
    }
}

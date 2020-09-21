import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: todayWeatherItem
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#FE8100" }
        GradientStop { position: 1.0; color: "#FE9808" }
    }

    property alias city: city.text
    property alias temperature: temperature.text
    property alias icon: icon.source
    property alias description: description.text
    property alias date: date.text

    ScaledImage {
        id: icon
        anchors.fill: parent
        scaling: 10
        padding: 40
    }
    ColorOverlay{
        anchors.fill: icon
        antialiasing: true
        source: icon
        color: "white"
    }

    Text {
        id: description
        font.pointSize: 50
        wrapMode: Text.WordWrap
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 5
            leftMargin: 5
        }
        color: "white"
    }

    Text {
        id: temperature
        font.pointSize: 28
        anchors {
            top: description.bottom
            topMargin: 5
        }
        color: "white"
    }

    Text {
        id: city
        font.pointSize: 50
        wrapMode: Text.WordWrap
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        anchors {
            bottom: parent.bottom
            bottomMargin: 80
        }
        color: "white"
    }

    Text {
        id: date
        font.pointSize: 28
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        anchors {
            top: city.bottom
            topMargin: 5
        }
        color: "white"
    }
}

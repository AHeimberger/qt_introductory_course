import QtQuick 2.0

Rectangle {
    id: todayWeatherItem
    color: "blue"

    property alias temperature: temperature.text
    property alias icon: icon.source
    property alias description: description.text

    ScaledImage {
        id: icon
        anchors.fill: parent
        scaling: 10
        padding: 40
    }

    Text {
        id: temperature
        font.pointSize: 28
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 5
            leftMargin: 5
        }
    }

    Text {
        id: description
        font.pointSize: 23
        wrapMode: Text.WordWrap
        width: parent.width
        horizontalAlignment: Text.AlignRight
        anchors {
            bottom: parent.bottom
            right: parent.right
            rightMargin: 5
            bottomMargin: 5
        }
    }
}

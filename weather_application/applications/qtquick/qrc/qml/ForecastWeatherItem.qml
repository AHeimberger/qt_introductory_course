import QtQuick 2.0
import QtQuick.Layouts 1.0

ColumnLayout {
    property alias temperatureRange: temperatureRange.text
    property alias day: day.text
    property alias icon: icon.source

    Text {
        id: day
        horizontalAlignment: Text.AlignHCenter
        Layout.fillWidth: true
        elide: Text.ElideRight
    }

    ScaledImage {
        id: icon
        scaling: 1.3
        Layout.fillWidth: true
        Layout.fillHeight: true
    }

    Text {
        id: temperatureRange
        horizontalAlignment: Text.AlignHCenter
        Layout.fillWidth: true
    }
}

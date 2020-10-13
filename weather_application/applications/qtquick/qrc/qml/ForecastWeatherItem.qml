import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtGraphicalEffects 1.0
import "."

ColumnLayout {
    property alias temperatureRange: temperatureRange.text
    property alias day: day.text
    property alias icon: icon.source

    Text {
        id: day
        horizontalAlignment: Text.AlignHCenter
        Layout.fillWidth: true
        elide: Text.ElideRight
        color: Style.forecast_item.font_color
    }

    Item {
        Layout.fillWidth: true
        Layout.fillHeight: true

        ScaledImage {
            id: icon
            anchors.fill: parent
            scaling: 1.3
        }

        ColorOverlay{
            source: icon
            anchors.fill: icon
            antialiasing: true
            color: Style.forecast_item.icon_color
        }
    }

    Text {
        id: temperatureRange
        horizontalAlignment: Text.AlignHCenter
        Layout.fillWidth: true
        color: Style.forecast_item.font_color
    }
}

import QtQuick 2.0
import QtQuick.Layouts 1.0

ColumnLayout {
    spacing: 0

    Rectangle {
        color: "red"
        Layout.preferredHeight: 50
        Layout.fillWidth: true
    }

    Rectangle {
        color: "green"
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
}

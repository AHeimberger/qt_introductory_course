import QtQuick 2.0

Item {
    Rectangle {
        id: topBar
        color: "red"
        height: 50
        width: parent.width
        x: 0
        y: 0
    }

    Rectangle {
        color: "green"
        height: parent.height - topBar.height
        width: parent.width
        x: 0
        y: topBar.height
    }
}

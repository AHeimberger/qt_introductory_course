import QtQuick 2.0

Column {
    Rectangle {
        id: topBar
        color: "red"
        height: 50
        width: parent.width
    }

    Rectangle {
        color: "green"
        height: parent.height - topBar.height
        width: parent.width
    }
}

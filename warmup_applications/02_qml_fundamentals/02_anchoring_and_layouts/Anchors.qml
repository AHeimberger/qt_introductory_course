import QtQuick 2.0

Item {
    Rectangle {
        id: topbar
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: 50
        color: "red"
    }

    Rectangle {
        anchors.top: topbar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        color: "green"
    }
}

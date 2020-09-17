import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    antialiasing: false
    implicitWidth: 40
    implicitHeight: 30
    color: parent.down ? "#d6d6d6" : "#f6f6f6"
    border.color: "#26282a"
    border.width: 1
    radius: 4
}

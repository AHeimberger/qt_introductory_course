import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    width: 170; height: 200
    visible: true

    Rectangle {
        id: yellowRectangle
        color: "yellow"
        x: 10; y: 20
        width: 50; height: 50
    }

    Rectangle {
        color: "green"
        x: yellowRectangle.x
        y: yellowRectangle.y + 100
        width: 50; height: 50
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (yellowRectangle.x === 100) {
                yellowRectangle.x = 10
            }
            else {
                yellowRectangle.x = 100
            }
        }
    }
}

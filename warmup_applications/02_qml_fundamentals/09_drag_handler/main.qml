import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 170; height: 200
    visible: true

    Rectangle {
        id: yellowRectangle
        color: "yellow"
        x: 10; y: 20
        width: 50; height: 50

        DragHandler {}
    }
}

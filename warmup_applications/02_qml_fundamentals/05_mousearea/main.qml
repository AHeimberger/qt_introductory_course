import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    width: 640; height: 480
    visible: true

    Item {
        id: myMouseArea
        anchors.fill: parent
        signal mouseAreaClicked

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.debug("hello mouse click")
                parent.mouseAreaClicked()
            }
        }

        onMouseAreaClicked: {
            console.debug("forwared mouse click via signal\n")
        }
    }
}

import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    width: 640; height: 480
    visible: true
    color: "green"

    Rectangle {
        id: rectangle1                      // what color does rectangle have per default? what happened to window color?
        anchors.centerIn: parent
        width: 400; height: 400
        border {
            color: "black"
            width: 2
        }
        clip: true                          // what is it doing?

        Rectangle {
            id: rectangle1_1
            // z:                           // what happens if you enable z index
            anchors.centerIn: parent
            width: 500; height: 200         // what happened here?
            color: "blue"
        }

        Rectangle {                         // what happened here?
            id: rectangle1_2
            anchors.centerIn: parent
            width: 200; height: 500;
            color: "red"
        }
    }
}

import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    width: 300; height: 300
    visible: true

    Rectangle {
        id: myRectangle
        width: 50; height: 50

        state: "idle"
        states: [
            State {
                name: "idle"

                PropertyChanges {
                    target: myRectangle
                    color: "yellow"
                    x: 10
                    y: 10
                    rotation: 0
                }
            },
            State {
                name: "s1"

                PropertyChanges {
                    target: myRectangle
                    color: "green"
                    x: 240
                    y: 240
                    rotation: 360
                }
            }
        ]

        transitions: Transition {
            ColorAnimation { duration: 1000 }
            NumberAnimation { properties: "x, y, rotation"; duration: 1000 }
        }
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: parent
        onClicked: {
            if (myRectangle.state === "idle") {
                myRectangle.state = "s1";
            } else {
                myRectangle.state = "idle"
            }
        }
    }
}

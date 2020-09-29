import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    width: 170; height: 200
    visible: true

    Rectangle {
        id: myRectangle
        x: 10; y: 20
        width: 50; height: 50

        state: "idle"
        states: [
            State {
                name: "idle"
                PropertyChanges { target: myRectangle; color: "yellow" }
            },
            State {
                name: "s1"
                PropertyChanges { target: myRectangle; color: "green" }
            },
            State {
                name: "s2"
                PropertyChanges { target: myRectangle; color: "red" }
            }
        ]
    }

    Text {
        text: "Please Click"
        anchors.centerIn: parent
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: parent
        onClicked: {
            if (myRectangle.state === "idle") {
                myRectangle.state = "s1";
            } else if (myRectangle.state === "s1") {
                myRectangle.state = "s2";
            } else if (myRectangle.state === "s2") {
                myRectangle.state = "s1";
            }
        }
    }
}

import QtQuick 2.0
import QtQml.StateMachine 1.0
import QtQuick.Window 2.12

Window {
    width: 170; height: 200
    visible: true

    Rectangle {
        id: myRectangle
        x: 10; y: 20
        width: 50; height: 50
        color: idle.active ? "yellow" : s1.active ? "green" : s2.active ? "red" : "gray"
    }

    Text {
        visible: s1.active || s2.active
        text: "Please Click"
        anchors.centerIn: parent
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: parent
    }

    StateMachine {
        id: stateMachine
        initialState: idle
        running: true

        State {
            id: idle

            TimeoutTransition {
                timeout: 1000
                targetState: s1
            }

            onEntered: console.debug("entered idle")
            onExited: console.debug("entered idle")
        }

        State {
            id: s1

            SignalTransition {
                signal: myMouseArea.clicked
                targetState: s2
            }

            onEntered: console.debug("entered s1")
            onExited: console.debug("entered s1")
        }

        State {
            id: s2

            SignalTransition {
                signal: myMouseArea.clicked
                targetState: idle
            }

            onEntered: console.debug("entered s2")
            onExited: console.debug("entered s2")
        }
    }
}

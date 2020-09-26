import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    id: root
    width: 640; height: 480
    visible: true

    readonly property int stepsize: 10
    property int someObjectPosX: (root.width/2 - someObject.width/2)
    property int someObjectPosY: (root.height/2 - someObject.height/2)

    function moveLeft() { someObjectPosX = someObjectPosX-stepsize; }
    function moveRight() { someObjectPosX = someObjectPosX+stepsize;  }
    function moveUp() { someObjectPosY = someObjectPosY-stepsize; }
    function moveDown() { someObjectPosY = someObjectPosY+stepsize; }

    Rectangle {
        width: 60; height: 60
        x: 10; y: 10

        Rectangle {
            id: leftButton
            color: "red"
            width: 20; height: 20
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            MouseArea { anchors.fill: parent; onClicked: moveLeft(); }
        }

        Rectangle {
            id: upButton
            color: "red"
            width: 20; height: 20
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            MouseArea { anchors.fill: parent; onClicked: moveUp(); }
        }

        Rectangle {
            id: rightButton
            color: "red"
            width: 20; height: 20
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            MouseArea { anchors.fill: parent; onClicked: moveRight(); }
        }

        Rectangle {
            id: downButton
            color: "red"
            width: 20; height: 20
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            MouseArea { anchors.fill: parent; onClicked: moveDown(); }
        }
    }


    Rectangle {
        id: someObject
        color: "green"
        width: 40; height: 40
        x: someObjectPosX
        y: someObjectPosY
    }
}

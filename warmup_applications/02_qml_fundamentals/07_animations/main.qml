import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    width: 640; height: 480
    visible: true

    Rectangle {
        id: yellowRectangle
        y: parent.height/2 - width/2
        width: 50; height: 50;
        color: "yellow"
        antialiasing: true

        SequentialAnimation on x{
            loops: Animation.Infinite
            PropertyAnimation { to: 640-yellowRectangle.width/2; duration: 3000 }
            PropertyAnimation { to: 0; duration: 1000 }
        }
    }

    Rectangle {
        anchors.centerIn: parent
        width: 100; height: 100;
        color: "green"
        antialiasing: true

        RotationAnimation on rotation {
            loops: Animation.Infinite
            from: 0
            to: 360
            duration: 5000
        }
    }
}

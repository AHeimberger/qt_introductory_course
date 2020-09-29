import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    width: 640; height: 480
    visible: true

    Column {
        anchors.centerIn: parent
        width: 100

        Text {
            text: "Name: " + cppPerson.name;
        }

        Text {
            text: "Alter: " + cppPerson.age
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (cppPerson.name === "Peter") {
                cppPerson.name = "Anton"
                cppPerson.age = 5
            }
            else {
                cppPerson.name = "Peter"
                cppPerson.age = 10
            }
        }
    }
}

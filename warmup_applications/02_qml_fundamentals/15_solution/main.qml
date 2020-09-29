import QtQuick 2.5
import QtQuick.Window 2.12
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.5

Window {
    width: 350; height: 450
    visible: true

    property var array: [
        { "name": "hans", "age": 10 },
        { "name": "susanne", "age": 13 },
        { "name": "jonas", "age": 12 },
        { "name": "elena", "age": 20 },
    ]

    function removeFromArray(index) {
        array.splice(index, 1);
        listView.model = array;
    }

    function addToArray(name, age) {
        array.push( { "name": name, "age": age})
        listView.model = array
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: array
            clip: true

            headerPositioning: ListView.OverlayHeader
            header: Rectangle {
                width: parent.width
                height: 60
                z: 2

                RowLayout {
                    anchors.fill: parent

                    Text {
                        Layout.preferredWidth: 100
                        text: "name"
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                    }

                    Text {
                        Layout.preferredWidth: 100
                        text: "age"
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                    }

                    Item {
                        Layout.preferredWidth: 40
                        Layout.preferredHeight: 40
                    }
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    color: "gray"
                    anchors.bottom: parent.bottom
                }
            }

            delegate: Item {
                width: parent.width
                height: 60

                RowLayout {
                    anchors.fill: parent

                    Text {
                        Layout.preferredWidth: 100
                        text: modelData.name
                        horizontalAlignment: Text.AlignLeft
                    }

                    Text {
                        Layout.preferredWidth: 100
                        text: modelData.age
                        horizontalAlignment: Text.AlignLeft
                    }

                    Button {
                        Layout.preferredWidth: 40
                        Layout.preferredHeight: 40
                        text: "X"
                        onClicked: removeFromArray(index)
                    }
                }

                Rectangle {
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: 1
                    color: "black"
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: false

            TextField {
                id: name
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                placeholderText: "name"
            }

            TextField {
                id: age
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                placeholderText: "age"
            }

            Button {
                Layout.preferredWidth: 40
                Layout.preferredHeight: 30
                text: "add"
                onClicked: addToArray(name.text, age.text)
            }
        }
    }
}

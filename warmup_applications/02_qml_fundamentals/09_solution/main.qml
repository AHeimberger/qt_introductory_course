import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Window {
    width: 350; height: 450
    visible: true

    property var array: [
        { "name": "hans", "age": 10 },
        { "name": "manuel", "age": 13 },
        { "name": "jonas", "age": 12 },
        { "name": "andreas", "age": 20 },
    ]

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: array
            delegate: Item {
                width: parent.width
                height: 60

                RowLayout {
                    anchors.fill: parent

                    Text {
                        Layout.preferredWidth: 100
                        text: modelData.name
                    }

                    Text {
                        Layout.preferredWidth: 100
                        text: modelData.age
                    }

                    Button {
                        Layout.preferredWidth: 40
                        Layout.preferredHeight: 40
                        text: "X"
                        onClicked: {
                            array.splice(index, 1);
                            listView.model = array;
                        }
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
                onClicked: {
                    array.push( { "name": name.text, "age": age.text})
                    listView.model = array
                }
            }
        }
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Item {
    id: viewSettings
    signal okClicked
    signal cancelClicked

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5

        Text {
            Layout.fillWidth: true
            text: "Locations:"
        }

        TextArea {
            id: locations
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: cppSettings.locations
            background: SelectionBackground {}
        }

        Text {
            Layout.fillWidth: true
            text: "Language:"
        }

        ComboBox {
            id: languages
            Layout.fillWidth: true
            background: SelectionBackground {}
            model: cppSettings.languagesAsList
        }

        RowLayout {
            Layout.preferredHeight: 50
            Layout.fillWidth: true

            Button {
                id: okButton
                text: "OK"
                background: SelectionBackground {}
                onClicked: {
                    cppSettings.locations = locations.text
                    cppSettings.language = languages.currentText
                    viewSettings.okClicked()
                }
            }

            Button {
                id: cancelButton
                text: "CANCEL"
                background: SelectionBackground {}
                onClicked: {
                    locations.text = cppSettings.locations
                    cppSettings.language = languages.currentText
                    viewSettings.cancelClicked()
                }
            }
        }
    }
}

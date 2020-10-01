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
            text: qsTr("Application ID:")
        }

        TextArea {
            id: appId
            Layout.fillWidth: true
            text: cppSettings.appId
            background: SelectionBackground {}
        }

        Text {
            Layout.fillWidth: true
            text: qsTr("Locations:")
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
            text: qsTr("Language:")
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
                text: qsTr("OK")
                background: SelectionBackground {}
                onClicked: {
                    cppSettings.appId = appId.text
                    cppSettings.locations = locations.text
                    cppSettings.language = languages.currentText
                    viewSettings.okClicked()
                }
            }

            Button {
                id: cancelButton
                text: qsTr("CANCEL")
                background: SelectionBackground {}
                onClicked: {
                    appId.text = cppSettings.appId
                    locations.text = cppSettings.locations
                    cppSettings.language = languages.currentText
                    viewSettings.cancelClicked()
                }
            }
        }
    }
}

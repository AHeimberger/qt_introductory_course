import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Item {
    id: viewInit

    signal okClicked

    ColumnLayout {
        anchors.centerIn: parent

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

        Button {
            id: okButton
            text: qsTr("OK")
            background: SelectionBackground {}
            onClicked: {
                cppSettings.appId = appId.text
                viewInit.okClicked()
            }
        }
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: settingsMenu
    signal buttonClicked

    ComboBox {
        id: locationBox
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: settingsButton.left
        anchors.margins: 10
        antialiasing: true
        background: SelectionBackground {}
        model: cppSettings.locationsAsList
        onCurrentTextChanged: cppSettings.location = locationBox.currentText
    }

    Button {
        id: settingsButton
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 10
        background: SelectionBackground {}
        onClicked: settingsMenu.buttonClicked()

        ScaledImage {
            scaling: 0.2
            source: "qrc:///settings/menu.svg"
            anchors.centerIn: parent
        }
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0

Window {
    id: mainWindow
    width: 360
    height: 640
    visible: true

    SwipeView {
        id: swipeView
        anchors.fill: parent
        interactive: false

        ViewWeather {
            onSettingsClicked: swipeView.currentIndex = 1
        }

        ViewSettings {
            onOkClicked: swipeView.currentIndex = 0
            onCancelClicked: swipeView.currentIndex = 0
        }
    }
}

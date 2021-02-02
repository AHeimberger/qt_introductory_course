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
        currentIndex: (cppSettings.appId === "" || cppSettings.appId === "YOUR_OPPENWEATHERMAP_APPID") ? 0 : 1

        ViewInit {
            onOkClicked: swipeView.currentIndex = 1
        }

        ViewWeather {
            onSettingsClicked: swipeView.currentIndex = 2
        }

        ViewSettings {
            onOkClicked: swipeView.currentIndex = 1
            onCancelClicked: swipeView.currentIndex = 1
        }
    }
}

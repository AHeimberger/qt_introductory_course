import QtQuick 2.1
import QtQuick.Window 2.12

Window {
    width: 640; height: 480
    visible: true

    ListModel {
        id: myModel
        ListElement { name: "hello student" }
        ListElement { name: "how are you doing" }
    }

    Column {
        Repeater {
            model: myModel
            Text { font.pixelSize: 30; text: name }
        }
    }
}

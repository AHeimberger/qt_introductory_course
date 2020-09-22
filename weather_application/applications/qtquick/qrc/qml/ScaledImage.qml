import QtQuick 2.0

Item {
    property int padding: 10
    property double scaling: 1.0
    property alias source: img.source

    height: img.paintedHeight
    width: img.paintedWidth

    Image {
        id: img
        anchors.centerIn: parent
        sourceSize: Qt.size(orgImage.sourceSize.width*parent.scaling, orgImage.sourceSize.height*parent.scaling )

        Image {
            id: orgImage
            source: parent.source
            width: 0
            height: 0
        }
    }
}

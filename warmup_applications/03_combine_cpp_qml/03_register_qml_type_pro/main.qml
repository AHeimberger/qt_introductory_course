import QtQuick 2.15
import QtQuick.Window 2.15
import com.bbvch.qmlcomponents 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyQmlType {
        width: 100
        height: 100
        x: 100
        y: 100
    }
}

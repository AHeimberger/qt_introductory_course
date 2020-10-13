pragma Singleton

import QtQuick 2.4

QtObject {
    property QtObject line: QtObject {
        readonly property color color: "black"
    }

    property QtObject today_item: QtObject {
        readonly property color font_color: "white"
        readonly property color gradient_start: "#FE8100"
        readonly property color gradient_stop: "#ff0000"
        readonly property color icon_color: "white"
    }

    property QtObject forecast_item: QtObject {
        readonly property color font_color: "black"
        readonly property color background_color: "white"
        readonly property color icon_color: "black"
        readonly property color line_color: "black"
    }
}

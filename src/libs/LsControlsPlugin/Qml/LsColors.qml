pragma Singleton
import QtQuick 2.5

QtObject {
    readonly property color transparentColor:  "#00000000"

    readonly property color  borderColor: "#80000000"
    readonly property double borderWidth: 1.5

    readonly property color  highlightColor: "#ff40ffff"
    readonly property double highlightWidth: 2

    readonly property color grooveColor:  "#80323343"

    readonly property color controlColor: "#80636687"

    readonly property color textColor: "#a0000000"

    readonly property font normalFont: Qt.font({family: "Helvetica", pointSize: 14});

    readonly property int margin: 16
    readonly property int stdwidth: 32
    readonly property int stdheight: 32
}

pragma Singleton
import QtQuick 2.5

QtObject {
    property color transparentColor:  "#00000000"

    property color  borderColor: "#80000000"
    property double borderWidth: 1.5

    property color  highlightColor: "#ff40ffff"
    property double highlightWidth: 2

    property color grooveColor:  "#80323343"

    property color controlColor: "#80636687"

    property color textColor: "#a0000000"

    property font normalFont: Qt.font({family: "Helvetica", pointSize: 14});
}

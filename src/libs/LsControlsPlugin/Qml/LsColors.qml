pragma Singleton
import QtQuick 2.5

QtObject {
    readonly property color textColor: "#a0ffffff"

    readonly property font normalFont: Qt.font({family: "Helvetica", pointSize: 14});

    readonly property int margin: 16
    readonly property int stdwidth: 16
    readonly property int stdheight: 16
}

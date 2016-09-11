import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Switch {
    id: lsSwitch
    property string textOn: "On"
    property string textOff: "Off"

    implicitWidth: 240
    implicitHeight: 64

    style: SwitchStyle {
        groove: Rectangle {
            implicitWidth: control.width
            implicitHeight: control.height
            radius: height/2
            color: LsColors.grooveColor
            border {
                width: LsColors.borderWidth
                color: LsColors.borderColor
            }
            Text {
                text: control.checked ? lsSwitch.textOn : lsSwitch.textOff
                font: LsColors.normalFont
                color: control.checked  ? LsColors.highlightColor: LsColors.textColor
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        handle: Item {
        }
    }
}


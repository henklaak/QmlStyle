import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Switch {
    id: lsSwitch
    property string textOn: "On"
    property string textOff: "Off"

    width: 60
    height: 40
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
                color: control.checked  ? LsColors.highlightColor: LsColors.borderColor
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        handle: Item {
            width: height

            Rectangle {
                anchors.fill: parent
                anchors.margins: 4

                radius: height/2
                color: LsColors.controlColor
                border {
                    width: (control.pressed ? LsColors.highlightWidth : LsColors.borderWidth)
                    color: (control.pressed ? LsColors.highlightColor : LsColors.borderColor)
                }
            }
        }
    }
}


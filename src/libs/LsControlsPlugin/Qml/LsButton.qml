import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Button {

    style: ButtonStyle {
        background:
            Rectangle {
            radius: control.height/2
            width: control.width
            height: control.height

            color: LsColors.controlColor
            border {
                width: (control.pressed ? LsColors.highlightWidth : LsColors.borderWidth)
                color: (control.pressed ? LsColors.highlightColor : LsColors.borderColor)
            }
        }
        label: Text {
            text: control.text
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: LsColors.textColor
            font: LsColors.normalFont
        }
    }
}

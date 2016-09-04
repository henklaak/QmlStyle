import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Slider {
    style: SliderStyle {
        groove: Rectangle {
            radius: control.height/2
            width: control.width
            height: control.height

            color: LsColors.grooveColor
            border {
                width: LsColors.borderWidth
                color: LsColors.borderColor
            }
        }

        handle: Item {
            height: 20
            width: height

            Rectangle {
                anchors.fill: parent
                anchors.margins: -10

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


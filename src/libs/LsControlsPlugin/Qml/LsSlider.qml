import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Slider {
    height: 32

    style: SliderStyle {
        groove:  Item {
            width: control.width
            height: control.height

            BorderImage {
                visible: true
                x: -32
                y: -32
                width: parent.width + 64
                height: parent.height + 64
                source: ("qrc:/LsControls/Images/Slider_%1_%2_%3.png")
                .arg(enabled ? "enabled" : "disabled")
                .arg(pressed ? "pressed" : "unpressed")
                .arg("unchecked")

                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
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


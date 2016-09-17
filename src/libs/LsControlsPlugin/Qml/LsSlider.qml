import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Slider {
    implicitWidth:  8 * LsColors.stdwidth
    implicitHeight: 2 * LsColors.stdheight

    style: SliderStyle {
        groove: Item {
            width: control.width
            height: control.height
            BorderImage {
                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + control.width + LsColors.margin
                height: LsColors.margin + control.height + LsColors.margin
                source: (("qrc:/LsControls/Images/Slider_%1_%2_%3.png")
                         .arg(control.enabled ? "enabled" : "disabled")
                         .arg(control.pressed ? "pressed" : "unpressed")
                         .arg("unchecked"))

                border.left:   LsColors.margin + LsColors.stdwidth
                border.right:  LsColors.margin + LsColors.stdwidth
                border.top:    LsColors.margin + LsColors.stdheight
                border.bottom: LsColors.margin + LsColors.stdheight

                Rectangle {
                    visible: false
                    anchors.fill: parent
                    color: "#40ff0000"
                }
            }
        }
        handle: Item {
            id: handle
            anchors.centerIn: parent
            width: 2 * LsColors.stdwidth
            height: 2 * LsColors.stdheight

            Image  {
                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + handle.width + LsColors.margin
                height: LsColors.margin + handle.height + LsColors.margin
                source: (("qrc:/LsControls/Images/SliderIndicator_%1_%2_%3.png")
                         .arg(control.enabled ? "enabled" : "disabled")
                         .arg(control.pressed ? "pressed" : "unpressed")
                         .arg("unchecked"))

                Rectangle {
                    visible: false
                    anchors.fill: parent
                    color: "#40ff0000"
                }
            }

        }
    }
    Rectangle {
        visible: false
        anchors.fill: parent
        color: "#40ff0000"
    }
}


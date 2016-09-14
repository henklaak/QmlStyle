import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

RadioButton {
    implicitWidth:  2 * LsColors.stdwidth
    implicitHeight: 2 * LsColors.stdheight

    style: RadioButtonStyle {
        background:  Item {
            BorderImage {
                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + 2 * LsColors.stdwidth + LsColors.margin
                height: LsColors.margin + 2 * LsColors.stdheight + LsColors.margin
                source: ("qrc:/LsControls/Images/RadioButton_%1_%2_%3.png")
                .arg(control.enabled ? "enabled" : "disabled")
                .arg(control.pressed ? "pressed" : "unpressed")
                .arg(control.checked ? "checked" : "unchecked")

                border.left: LsColors.margin + LsColors.stdwidth/4
                border.right: LsColors.margin + LsColors.stdwidth/4
                border.top: LsColors.margin + LsColors.stdheight/4
                border.bottom: LsColors.margin + LsColors.stdheight/4

                Rectangle {
                    visible: false
                    anchors.fill: parent
                    color: "#40ff0000"
                }
            }
        }
        indicator:  Item {
            width: 2 * LsColors.stdwidth
            height: 2 * LsColors.stdheight
        }
        spacing: 5
        label: Text {
            text: control.text
            color: LsColors.textColor
            font: LsColors.normalFont
        }
    }
    Rectangle {
        visible: false
        anchors.fill: parent
        color: "#40ff0000"
    }
}


import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

ComboBox {
    implicitWidth: 8 * LsColors.stdwidth
    implicitHeight: 3 * LsColors.stdheight

    style: ComboBoxStyle {
        background: Item {
            width: control.width
            height: control.height
            BorderImage {
                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + 8 * LsColors.stdwidth + LsColors.margin
                height: LsColors.margin + 3 * LsColors.stdheight + LsColors.margin

                source: ("qrc:/LsControls/Images/ComboBox_%1_%2_%3.png")
                .arg(control.enabled ? "enabled" : "disabled")
                .arg(control.pressed ? "pressed" : "unpressed")
                .arg("unchecked")

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

        textColor: LsColors.textColor
        font: LsColors.normalFont
    }
    Rectangle {
        visible: false
        anchors.fill: parent
        color: "#40ff0000"
    }
}

import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

TextField {
    implicitWidth:  4 * LsColors.stdwidth
    implicitHeight: 2 * LsColors.stdheight

    style: TextFieldStyle {
        background: Item {
            width: control.width
            height: control.height
            BorderImage {
                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + 4 * LsColors.stdwidth + LsColors.margin
                height: LsColors.margin + 2 * LsColors.stdheight + LsColors.margin

                source: ("qrc:/LsControls/Images/TextField_%1_%2_%3.png")
                .arg(control.enabled ? "enabled" : "disabled")
                .arg("unpressed")
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

//        font.family: LsColors.normalFontFamily
//        font.pointSize: LsColors.normalFontPointSize
//        font.bold: LsColors.normalFontBold
    }
    Rectangle {
        visible: false
        anchors.fill: parent
        color: "#40ff0000"
    }
}


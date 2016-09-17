import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

TextField {
    implicitWidth:  8 * LsColors.stdwidth
    implicitHeight: 3 * LsColors.stdheight

    style: TextFieldStyle {
        background: Item {
            width: control.width
            height: control.height
            BorderImage {
                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + control.width + LsColors.margin
                height: LsColors.margin + control.height + LsColors.margin

                source: ("qrc:/LsControls/Images/TextField_%1_%2_%3.png")
                .arg(control.enabled ? "enabled" : "disabled")
                .arg("unpressed")
                .arg("unchecked")

                border.left: LsColors.margin + LsColors.stdwidth
                border.right: LsColors.margin + LsColors.stdwidth
                border.top: LsColors.margin + LsColors.stdheight
                border.bottom: LsColors.margin + LsColors.stdheight

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


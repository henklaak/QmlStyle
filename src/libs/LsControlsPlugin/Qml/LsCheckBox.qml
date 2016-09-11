import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

CheckBox {
    width: 32
    height: 32

    style: CheckBoxStyle {
        background: Item {
            width: control.width
            height: control.height
            BorderImage {
                x: -32
                y: -32
                width: parent.width + 64
                height: parent.height + 64
                source: ("qrc:/LsControls/Images/CheckBox_%1_%2_%3.png")
                .arg(control.enabled ? "enabled" : "disabled")
                .arg(control.pressed ? "pressed" : "unpressed")
                .arg(control.checked ? "checked" : "unchecked")

                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
            }
        }
        label: Text {
            // TODO
            text: "hai" //control.text
            //anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: LsColors.textColor
            font: LsColors.normalFont
        }
        indicator:  Rectangle {
            // TODO
            visible: false
            x: control.width * 0.2
            implicitWidth: control.width*0.6
            implicitHeight: control.width*0.6
            radius: height*0.15
            color: control.checked ? LsColors.highlightColor : LsColors.transparentColor
        }
    }
}


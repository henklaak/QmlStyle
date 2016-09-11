import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

CheckBox {
    //implicitWidth: 240
    implicitHeight: 32

    style: CheckBoxStyle {
        background: Item {
            width: control.width
            height: control.height
            Image {
                x: -32
                y: -32
                source: ("qrc:/LsControls/Images/CheckBox_%1_%2_%3.png")
                .arg(control.enabled ? "enabled" : "disabled")
                .arg(control.pressed ? "pressed" : "unpressed")
                .arg(control.checked ? "checked" : "unchecked")
            }
        }
        indicator:  Item {
            width: 32
            height: 32
        }
        spacing: 5
        label: Text {
            text: control.text
            color: LsColors.textColor
            font: LsColors.normalFont
        }
    }
}


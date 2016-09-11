import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

RadioButton {
    implicitWidth: 240
    implicitHeight: 32

    style: RadioButtonStyle {
        background:  Item {
            Image {
                x: -32
                y: -32
                source: ("qrc:/LsControls/Images/RadioButton_%1_%2_%3.png")
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


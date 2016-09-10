import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

RadioButton {
    width: 32
    height: 32

    style: RadioButtonStyle {
        background:  Item {
            BorderImage {
                x: -32
                y: -32
                width: parent.width + 64
                height: parent.height + 64
                source: "qrc:/LsControls/Images/RadioButton.png"
                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
            }
        }
        indicator:  Rectangle {
            x: control.width * 0.2
            implicitWidth: control.width * 0.6
            implicitHeight: control.width * 0.6
            radius: height/2.0
            color: control.checked ? LsColors.highlightColor : LsColors.transparentColor
        }
    }
}


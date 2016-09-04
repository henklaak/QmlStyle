import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

CheckBox {
    width: 30
    height: 30

    style: CheckBoxStyle {
        background: Rectangle {
            radius: height/4
            width: control.width
            height: control.height

            color: LsColors.controlColor
            border {
                width: (control.pressed ? LsColors.highlightWidth : LsColors.borderWidth)
                color: (control.pressed ? LsColors.highlightColor : LsColors.borderColor)

            }
        }
        indicator:  Rectangle {
            x: control.width * 0.2
            implicitWidth: control.width*0.6
            implicitHeight: control.width*0.6
            radius: height*0.15
            color: control.checked ? LsColors.highlightColor : LsColors.transparentColor
        }
    }
}


import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

ComboBox {

    style: ComboBoxStyle {
        background: Rectangle {
            radius: 5
            width: control.width
            height: control.height

            color: LsColors.grooveColor
            border {
                width: (control.pressed ? LsColors.highlightWidth : LsColors.borderWidth)
                color: (control.pressed ? LsColors.highlightColor : LsColors.borderColor)
            }
        }

        textColor: LsColors.textColor
        font: LsColors.normalFont
    }
}

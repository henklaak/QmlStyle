import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

TextField {
    style: TextFieldStyle {
        background: Rectangle {
            implicitWidth: control.width
            implicitHeight: control.height
            radius: 5
            color: LsColors.grooveColor
            border {
                width: LsColors.borderWidth
                color: LsColors.borderColor
            }
        }
        textColor: LsColors.textColor
        font: LsColors.normalFont

//        font.family: LsColors.normalFontFamily
//        font.pointSize: LsColors.normalFontPointSize
//        font.bold: LsColors.normalFontBold
    }
}


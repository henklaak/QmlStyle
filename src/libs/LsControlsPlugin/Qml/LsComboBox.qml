import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

ComboBox {

    style: ComboBoxStyle {
        background: Item {
            width: control.width
            height: control.height
            BorderImage {
                x: -32
                y: -32
                width: parent.width + 64
                height: parent.height + 64
                source: "qrc:/LsControls/Images/ComboBox.png"
                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
            }
        }

        textColor: LsColors.textColor
        font: LsColors.normalFont
    }
}

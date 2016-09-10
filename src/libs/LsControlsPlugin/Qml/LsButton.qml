import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Button {
    style: ButtonStyle {
        background: Item {
            BorderImage {
                x: -32
                y: -32
                width: parent.width + 64
                height: parent.height + 64
                source: "qrc:/LsControls/Images/Button.png"
                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
            }
        }
        label: Text {
            text: control.text
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: LsColors.textColor
            font: LsColors.normalFont
        }
    }
}

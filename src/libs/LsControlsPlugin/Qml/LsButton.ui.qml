import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Button {
    text: "hai"
    style: ButtonStyle {
        background:
            BorderImage {
            x: -10
            anchors.fill: parent
            anchors.margins: -10
            source: (control.pressed
                     ? "qrc:/LsControls/Images/button_on2.png"
                     : (control.hovered
                        ? "qrc:/LsControls/Images/button_on.png"
                        : "qrc:/LsControls/Images/button.png"))
            border.left: 20
            border.right: 20
            border.top: 20
            border.bottom: 20
        }
        label: LsText {
            text: control.text
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}

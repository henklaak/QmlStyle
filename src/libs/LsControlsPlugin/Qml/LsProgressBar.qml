import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

ProgressBar {
    style: ProgressBarStyle {
        background: Item {
            width: control.width
            height: control.height

            BorderImage {
                visible: true
                x: -32
                y: -32
                width: parent.width + 64
                height: parent.height + 64
                source: ("qrc:/LsControls/Images/ProgressBar_%1_%2_%3.png")
                .arg(enabled ? "enabled" : "disabled")
                .arg("unpressed")
                .arg("unchecked")

                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
            }
        }

        progress:
            Item {
            width: control.width
            height: control.height
            Rectangle {
                anchors.fill: parent
                anchors.margins: 4

                radius: height/2

                color: LsColors.highlightColor
            }
        }
    }
}

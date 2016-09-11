import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

ProgressBar {
    implicitWidth: 240
    implicitHeight: 32

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
                .arg(control.enabled ? "enabled" : "disabled")
                .arg("unpressed")
                .arg("unchecked")

                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
            }
        }

        progress: Item {
            anchors.margins: 0
            onWidthChanged: {
                console.error("parentwidth " + width)
                console.error("controlwidth " + control.width)
            }
            BorderImage {
                // parent 0..240
                // image 32 + 200 + 32
                property double perc: parent.width / control.width
                onPercChanged: console.error("Perc " + perc)

                x: -32
                y: -32
                height: parent.height+64
                width: 64 + perc * (240)
                onWidthChanged: console.error("width " + width)

                source: ("qrc:/LsControls/Images/ProgressBarIndicator_%1_%2_%3.png")
                .arg("enabled")
                .arg("unpressed")
                .arg("unchecked")

                border.left: 32 + Math.min(10,perc*100)
                border.right: 32 + Math.min(10,perc*100)
                border.top: 32 + Math.min(10,perc*100)
                border.bottom: 32 + Math.min(10,perc*100)
            }
        }
    }
}

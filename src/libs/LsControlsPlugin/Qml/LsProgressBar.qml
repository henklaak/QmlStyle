import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

ProgressBar {
    implicitWidth: 4 * LsColors.stdwidth
    implicitHeight: 1 * LsColors.stdheight

    style: ProgressBarStyle {
        background: Item {
            width: control.width
            height: control.height

            BorderImage {
                visible: true
                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + 4 * LsColors.stdwidth + LsColors.margin
                height: LsColors.margin + 1 * LsColors.stdheight + LsColors.margin

                source: ("qrc:/LsControls/Images/ProgressBar_%1_%2_%3.png")
                .arg(control.enabled ? "enabled" : "disabled")
                .arg("unpressed")
                .arg("unchecked")

                border.left: LsColors.margin + LsColors.stdwidth/4
                border.right: LsColors.margin + LsColors.stdwidth/4
                border.top: LsColors.margin + LsColors.stdheight/4
                border.bottom: LsColors.margin + LsColors.stdheight/4

                Rectangle {
                    visible: false
                    anchors.fill: parent
                    color: "#40ff0000"
                }
            }
        }

        progress: Item {
            BorderImage {
                property double perc: parent.width / control.width

                x: -LsColors.margin
                y: -LsColors.margin
                width:  LsColors.margin + perc * 4 * LsColors.stdwidth + LsColors.margin
                height: LsColors.margin + 1 * LsColors.stdheight + LsColors.margin

                source: ("qrc:/LsControls/Images/ProgressBarIndicator_%1_%2_%3.png")
                .arg("enabled")
                .arg("unpressed")
                .arg("unchecked")

                border.left: LsColors.margin + Math.min(LsColors.stdwidth/4,perc*100)
                border.right: LsColors.margin + Math.min(LsColors.stdwidth/4,perc*100)
                border.top: LsColors.margin + Math.min(LsColors.stdheight/4,perc*100)
                border.bottom: LsColors.margin + Math.min(LsColors.stdheight/4,perc*100)

                Rectangle {
                    visible: false
                    anchors.fill: parent
                    color: "#40ff0000"
                }
            }
        }
    }
    Rectangle {
        visible: false
        anchors.fill: parent
        color: "#40ff0000"
    }
}

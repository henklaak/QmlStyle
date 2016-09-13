import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import LsControls 1.0

Slider {
    implicitWidth: 240
    implicitHeight: 32

    style: SliderStyle {
        groove: Item {
            width: control.width
            height: control.height

            BorderImage {
                visible: true
                x: -32
                y: -32
                width: parent.width + 64
                height: parent.height + 64
                source: (("qrc:/LsControls/Images/Slider_%1_%2_%3.png")
                         .arg(control.enabled ? "enabled" : "disabled")
                         .arg(control.pressed ? "pressed" : "unpressed")
                         .arg("unchecked"))

                border.left: 64
                border.right: 64
                border.top: 64
                border.bottom: 64
            }
        }
        handle: Item {
            anchors.centerIn: parent
            implicitWidth: 32
            implicitHeight: 32

            Image {
                x: -32
                y: -32
                source: (("qrc:/LsControls/Images/SliderIndicator_%1_%2_%3.png")
                         .arg(control.enabled ? "enabled" : "disabled")
                         .arg(control.pressed ? "pressed" : "unpressed")
                         .arg("unchecked"))
            }

        }
    }
}


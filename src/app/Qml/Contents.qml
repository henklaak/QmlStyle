import QtQuick 2.5

import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import LsControls 1.0
import QtQuick.Layouts 1.0

Item {
    ColumnLayout {
        spacing: 10
        anchors.fill: parent

        LsLabel {
            id: label1
            text: "Demo reel!"
            Layout.fillWidth: true
        }

        LsSlider {
            id: slider1
            minimumValue: 0
            maximumValue: 100
            Layout.fillWidth: true
        }

        LsProgressBar {
            id: progressBar1
            minimumValue: 0
            maximumValue: 100
            value: slider1.value
            Layout.fillWidth: true
        }

        LsTextField {
            id: textField1
            text: "test1"
            Layout.fillWidth: true
        }

        LsTextField {
            id: textField2
            text: "test2"
            Layout.fillWidth: true
        }

        LsComboBox {
            id: comboBox1
            //editable: true
            Layout.fillWidth: true
        }

        ExclusiveGroup { id: pickGroup }

        LsRadioButton {
            id: radioButton1
            text: "Pick me!"
            exclusiveGroup: pickGroup
            checked: true
            Layout.fillWidth: true
        }

        LsRadioButton {
            id: radioButton2
            text: "No, me!"
            exclusiveGroup: pickGroup
            Layout.fillWidth: true
        }

        LsRadioButton {
            id: radioButton3
            text: "Or me!"
            exclusiveGroup: pickGroup
            Layout.fillWidth: true
        }


        LsButton {
            id: button1
            checkable: true
            checked: true
            text: "Toggle me"
            Layout.fillWidth: true
        }

        LsButton {
            id: button2
            text: "Press m23423e"
            Layout.fillWidth: true
        }

        LsButton {
            id: button3
            text: "Can't touch"
            checkable: true
            enabled: false
            Layout.fillWidth: true
        }

        LsCheckBox {
            id: checkBox1
            text: "Add me!"
            Layout.fillWidth: true
        }

        LsCheckBox {
            id: checkBox2
            text: "And me!"
            Layout.fillWidth: true
        }

        LsCheckBox {
            id: checkBox3
            text: "Me too!"
            Layout.fillWidth: true
        }
    }
}

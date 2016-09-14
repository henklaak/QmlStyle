import QtQuick 2.5

import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import LsControls 1.0
import QtQuick.Layouts 1.0

Item {
    width: 800
    height: 800


    ColumnLayout {
        x: 0
        y: 0

        LsLabel {
            id: label1
            text: "Demo reel!"
        }

        LsSlider {
            id: slider1
            minimumValue: 0
            maximumValue: 100
        }

        LsProgressBar {
            id: progressBar1
            minimumValue: 0
            maximumValue: 100
            value: slider1.value
        }

        LsTextField {
            id: textField1
            text: "test1"
        }

        LsTextField {
            id: textField2
            text: "test2"
        }

        LsComboBox {
            id: comboBox1
        }

        ExclusiveGroup { id: pickGroup }

        LsRadioButton {
            id: radioButton1
            text: "Pick me!"
            exclusiveGroup: pickGroup
            checked: true
        }

        LsRadioButton {
            id: radioButton2
            text: "No, me!"
            exclusiveGroup: pickGroup
        }

        LsRadioButton {
            id: radioButton3
            text: "Or me!"
            exclusiveGroup: pickGroup
        }


        LsButton {
            id: button1
            checkable: true
            checked: true
            text: "Toggle me"
        }

        LsButton {
            id: button2
            text: "Press me"
        }

        LsButton {
            id: button3
            text: "Can't touch"
            width: 600
            checkable: true
            enabled: false
        }

        LsCheckBox {
            id: checkBox1
            text: "Add me!"
        }

        LsCheckBox {
            id: checkBox2
            text: "And me!"
        }

        LsCheckBox {
            id: checkBox3
            text: "Me too!"
        }

//        LsSwitch {
//            id: switch1
//        }

//        LsSwitch {
//            id: switch2
//            checked: true
//        }

    }
}

import QtQuick 2.5

import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import LsControls 1.0

Item {
    width: 1200
    height: 1542

    Label {
        x: 0
        y: 0
    }
    LsLabel {
        x: 10
        y: 10
    }

    LsComboBox {
        x: 102
        y: 228;
        width: 210
        height: 64
    }

    LsTextField {
        x: 388
        y: 256
        width: 280
        height: 50
        text: "test"
    }
    LsTextField {
        x: 388
        y: 331
        width: 280
        height: 50
        text: "test"
    }
    LsLabel {
        x: 388
        y: 412
        width: 120
        height: 64
        text: "Lost Password?"
    }
    LsButton {
        x: 548
        y: 412
        width: 120
        height: 64
        checkable: true
        checked: true
        text: "Pressme"
    }

    LsSlider {
        id: slider
        x: 102
        y: 715
        width: 440
        height: 32
        minimumValue: 0
        maximumValue: 100
    }
    LsRadioButton {
        x: 953
        y: 635
    }
    LsRadioButton {
        x: 1010
        y: 635
        checked: true
    }
    LsRadioButton {
        x: 1068
        y: 635
        checked: true
        pressed: true
    }
    LsCheckBox {
        x: 953
        y: 705
    }
    LsCheckBox {
        x: 1010
        y: 705
        checked: true
    }
    LsCheckBox {
        x: 1068
        y: 705
        checked: true
        pressed: true
    }
    LsProgressBar {
        x: 102
        y: 804
        width: 440
        height: 23
        minimumValue: 0
        maximumValue: 100
        value: slider.value
    }
    LsSwitch {
        x: 490
        y: 889
        width: 135
        height: 50
    }
    LsSwitch {
        x: 702
        y: 889
        width: 135
        height: 50
        checked: true
    }
    LsButton {
        x: 454
        y: 1062
        width: 214
        height: 64
        text: "Pressme2"
    }
    LsButton {
        x: 454
        y: 1152
        width: 214
        height: 64
        text: "Pressme"
        checkable: true
        enabled: false
    }
    LsButton {
        x: 454
        y: 1241
        width: 214
        height: 64
        text: "Pressme"
        checkable: true
        checked: true
    }
}

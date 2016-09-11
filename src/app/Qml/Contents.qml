import QtQuick 2.5

import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import LsControls 1.0

Item {
    width: 800
    height: 600

    LsComboBox {
        x: 24
        y: 25
        width: 210
        height: 64
    }

    LsTextField {
        x: 267
        y: 32
        width: 280
        height: 50
        text: "test"
    }
    LsTextField {
        x: 267
        y: 102
        width: 280
        height: 50
        text: "test"
    }
    LsLabel {
        x: 580
        y: 32
        width: 120
        height: 64
        text: "Lost Password?"
    }
    LsButton {
        x: 580
        y: 68
        width: 120
        height: 64
        checkable: true
        checked: true
        text: "Pressme"
    }

    LsSlider {
        id: slider
        x: 267
        y: 175
        width: 440
        height: 32
        minimumValue: 0
        maximumValue: 100
    }
    LsRadioButton {
        x: 24
        y: 174
    }
    LsRadioButton {
        x: 81
        y: 174
        checked: true
    }
    LsRadioButton {
        x: 139
        y: 174
        checked: true
        pressed: true
    }
    LsCheckBox {
        x: 24
        y: 244
    }
    LsCheckBox {
        x: 81
        y: 244
        checked: true
    }
    LsCheckBox {
        x: 139
        y: 244
        checked: true
        pressed: true
    }
    LsProgressBar {
        x: 267
        y: 244
        width: 440
        height: 23
        minimumValue: 0
        maximumValue: 100
        value: slider.value
    }
    LsSwitch {
        x: 24
        y: 312
        width: 135
        height: 50
    }
    LsSwitch {
        x: 24
        y: 382
        width: 135
        height: 50
        checked: true
    }
    LsButton {
        x: 267
        y: 318
        width: 214
        height: 64
        text: "Pressme2"
    }
    LsButton {
        x: 267
        y: 408
        width: 214
        height: 64
        text: "Pressme"
        checkable: true
        enabled: false
    }
    LsButton {
        x: 267
        y: 497
        width: 214
        height: 64
        text: "Pressme"
        checkable: true
        checked: true
    }
}

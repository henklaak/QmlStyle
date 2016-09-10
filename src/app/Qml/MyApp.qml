import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

import LsControls 1.0

LsApplicationWindow {
    x: 200
    y: 200
    width: 1200
    height: 1542
    visible: true

    Contents {
        RadialGradient {
            anchors.fill: parent
                 gradient: Gradient {
                     GradientStop { position: 0.0; color: "#00000000" }
                     GradientStop { position: 1.0; color: "#50000000" }
                 }}
        id: contents
        anchors.fill: parent
    }
}

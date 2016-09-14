import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

ApplicationWindow {
    width: 800
    height: 800
    visible: true

    Rectangle {
        anchors.fill: parent
        color: "#334f83"
    }
//    Image {
//        anchors.fill: parent
//        source: "qrc:/LsControls/Images/backgroundtile.png"
//        fillMode: Image.Tile
//    }

    Contents {
        anchors.fill: parent
        anchors.margins: 20
    }
    RadialGradient {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#00000000" }
            GradientStop { position: 1.0; color: "#40000000" }
        }
    }
}

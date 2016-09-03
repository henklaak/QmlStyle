import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import LsControls 1.0


ScrollView {
    width: 1200
    height: 1542

    LsComboBox { x: 102; y: 228; width: 210; height: 64; }

    LsTextField { x: 388; y: 256; width: 280; height: 50; }
    LsTextField { x: 388; y: 331; width: 280; height: 50; }
    LsLabel { x: 388; y: 412; width: 120; height: 64; text: "Lost Password?"}
    LsButton { x: 548; y: 412; width: 120; height: 64; checkable: true; checked: true; }

    LsSlider { x: 102; y: 715; width: 440; height: 14; }
    LsRadioButton { x:  953; y: 635; width: 30; height: 30; }
    LsRadioButton { x: 1010; y: 635; width: 30; height: 30; checked: true; }
    LsRadioButton { x: 1068; y: 635; width: 30; height: 30; checked: true; pressed: true; }

    LsCheckBox { x:  953; y: 705; width: 30; height: 30; }
    LsCheckBox { x: 1010; y: 705; width: 30; height: 30; checked: true; }
    LsCheckBox { x: 1068; y: 705; width: 30; height: 30; checked: true; pressed: true; }

    LsProgressBar { x: 102; y: 804; width: 440; height: 23; }

    LsSwitch{ x: 490; y: 889; width: 135; height: 50; }
    LsSwitch{ x: 702; y: 889; width: 135; height: 50; checked: true; }

    LsButton { x: 454; y: 1062; width: 214; height: 64; }
    LsButton { x: 454; y: 1152; width: 214; height: 64; checkable: true; }
    LsButton { x: 454; y: 1241; width: 214; height: 64; checkable: true; checked: true; }
}

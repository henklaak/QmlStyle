add_library(LsControlsPlugin SHARED
    lscontrolsplugin.cpp
    lscontrolsplugin.qrc
    Qml/LsApplicationWindow.ui.qml
    Qml/LsButton.ui.qml
    Qml/LsCheckBox.ui.qml
    Qml/LsComboBox.ui.qml
    Qml/LsLabel.ui.qml
    Qml/LsProgressBar.ui.qml
    Qml/LsRadioButton.ui.qml
    Qml/LsSlider.ui.qml
    Qml/LsSwitch.ui.qml
    Qml/LsText.ui.qml
    Qml/LsTextField.ui.qml
    qmldir)

target_include_directories(LsControlsPlugin
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(LsControlsPlugin
    Qt5::Core
    Qt5::Qml)

install(
    TARGETS LsControlsPlugin
    LIBRARY DESTINATION ${BINDIR})

install(
    FILES qmldir
    DESTINATION ${BINDIR}/LsControls)


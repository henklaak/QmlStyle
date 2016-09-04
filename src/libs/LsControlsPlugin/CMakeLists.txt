add_library(LsControlsPlugin SHARED
    lscontrolsplugin.cpp
    lscontrolsplugin.qrc
    Qml/LsApplicationWindow.qml
    Qml/LsButton.qml
    Qml/LsCheckBox.qml
    Qml/LsColors.qml
    Qml/LsComboBox.qml
    Qml/LsLabel.qml
    Qml/LsProgressBar.qml
    Qml/LsRadioButton.qml
    Qml/LsSlider.qml
    Qml/LsSwitch.qml
    Qml/LsText.qml
    Qml/LsTextField.qml
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


file(GLOB qmlfiles Qml/*.qml Images/*.png)

add_library(LsControlsPlugin SHARED
    lscontrolsplugin.cpp
    lscontrolsplugin.qrc
    ${qmlfiles}
    qmldir)

target_include_directories(LsControlsPlugin
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(LsControlsPlugin
    Qt5::Core
    Qt5::Qml)

install(
    TARGETS LsControlsPlugin
    LIBRARY DESTINATION ${BINDIR}/LsControls)

install(
    FILES qmldir
    DESTINATION ${BINDIR}/LsControls)

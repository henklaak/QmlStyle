file(GLOB qmlfiles Qml/*.qml)

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

add_custom_command(
    TARGET LsControlsPlugin
    POST_BUILD
    COMMAND qmlplugindump  LsControls 1.0 > plugins.qmltypes
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

install(
    TARGETS LsControlsPlugin
    LIBRARY DESTINATION ${BINDIR})

install(
    FILES qmldir "${CMAKE_CURRENT_BINARY_DIR}/plugins.qmltypes"
    DESTINATION ${BINDIR}/LsControls)



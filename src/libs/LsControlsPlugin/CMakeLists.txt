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

add_custom_command(
    TARGET LsControlsPlugin
    POST_BUILD
    COMMAND  /home/henklaak/Qt/5.7/gcc_64/bin/qmlplugindump -v LsControls 2.5 > LsControls.qmltypes
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

install(
    TARGETS LsControlsPlugin
    LIBRARY DESTINATION ${BINDIR}/LsControls)

install(
    FILES qmldir "${CMAKE_CURRENT_BINARY_DIR}/LsControls.qmltypes"
    DESTINATION ${BINDIR}/LsControls)



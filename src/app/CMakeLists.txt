add_executable(MyApp
    myapp.cpp
    myapp.qrc
    Qml/MyApp.qml
    Qml/Contents.ui.qml)

target_link_libraries(MyApp
    Qt5::Core
    Qt5::Qml
    Qt5::Widgets)

install(
    TARGETS MyApp
    RUNTIME DESTINATION ${BINDIR})



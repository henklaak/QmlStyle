add_executable(Generator
    generator.cpp
    lscontrolsrenderer.cpp)

target_link_libraries(Generator
    Qt5::Core
    Qt5::Qml
    Qt5::Widgets)

install(
    TARGETS Generator
    RUNTIME DESTINATION ${BINDIR})

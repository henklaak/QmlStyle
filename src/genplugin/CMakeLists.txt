add_executable(Generator
    generator.cpp
    lscombobox.cpp
    lscontrols.cpp
    lsbutton.cpp
    lscheckbox.cpp
    lsprogressbar.cpp
    lsradiobutton.cpp
    lsslider.cpp
    lstextfield.cpp
    )

target_link_libraries(Generator
    Qt5::Core
    Qt5::Qml
    Qt5::Widgets)

install(
    TARGETS Generator
    RUNTIME DESTINATION ${BINDIR})

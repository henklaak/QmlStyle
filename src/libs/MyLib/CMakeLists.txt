add_library(MyLib SHARED
    myclass.cpp)

target_include_directories(MyLib
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(MyLib
    Qt5::Core)


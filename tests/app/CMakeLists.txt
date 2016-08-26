add_executable(TestMyApp
    testmyapp.cpp)

target_link_libraries(TestMyApp
    Qt5::Test)

add_test(TestMyApp
    TestMyApp)


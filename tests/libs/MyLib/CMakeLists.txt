add_executable(TestMyClass
    testmyclass.cpp)

target_link_libraries(TestMyClass
    MyLib
    Qt5::Test)

add_test(TestMyClass
    TestMyClass)

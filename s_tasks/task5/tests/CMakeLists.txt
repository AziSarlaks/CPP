include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(mytst_exec my_test.cpp)

target_link_libraries(
    mytst_exec PUBLIC mylib GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(mytst_exec)

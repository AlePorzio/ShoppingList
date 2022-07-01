cmake_minimum_required(VERSION 3.22)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-main)
set(gtest_SOURCE_DIR, lib/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES ClientViewTestFixture.cpp ShoppingListTestFixture.cpp runAllTests.cpp ObserverClassTest.cpp ObserverClassTest.h SubjectClassTest.cpp SubjectClassTest.h ObserverTest.cpp)
add_executable(runShoppingListTests ${SOURCE_TEST_FILES})
target_link_libraries(runShoppingListTests gtest gtest_main core)
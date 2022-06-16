cmake_minimum_required(VERSION 3.22)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 11)

add_executable(ShoppingList main.cpp Subject.h Observer.h Client.cpp Client.h ShoppingList.cpp ShoppingList.h Product.cpp Product.h test/ClientTest.cpp)

add_subdirectory(test)
add_subdirectory(lib/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
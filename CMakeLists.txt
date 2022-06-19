cmake_minimum_required(VERSION 3.22)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES ShoppingList Subject.h Observer.h ClientView.cpp ClientView.h ShoppingList.cpp ShoppingList.h Product.cpp Product.h)
add_executable(ShoppingList main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ShoppingList core)
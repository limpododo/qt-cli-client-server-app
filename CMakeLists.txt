cmake_minimum_required(VERSION 3.27)

project(inobitec_test_task)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_subdirectory(client)
add_subdirectory(server)

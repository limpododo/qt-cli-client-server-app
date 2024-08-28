cmake_minimum_required(VERSION 3.27)

set(APP_NAME server)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE APP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE APP_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${APP_NAME} ${APP_SRC} ${APP_HDRS})

target_include_directories(${APP_NAME} PUBLIC app/include)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Core Qt6::Network)
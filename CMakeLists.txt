cmake_minimum_required(VERSION 2.8)

project(image_projector)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("inc")
file(GLOB SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

cmake_minimum_required(VERSION 3.16)


project(laba18)

set(CMAKE_CXX_STANDART 11)

file(GLOB CPPS "*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})


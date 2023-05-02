cmake_minimum_required(VERSION 3.10)
project(P06)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCE "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(P06 ${SOURCE} ${HEADERS})
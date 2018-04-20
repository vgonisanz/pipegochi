cmake_minimum_required(VERSION 3.11)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../arduino-cmake/cmake/ArduinoToolchain.cmake)

message(STATUS "Using toolchain at: ${CMAKE_TOOLCHAIN_FILE}")

set(PROJ_NAME pipegochi)
project(${PROJ_NAME})

#set(${PROJ_NAME}_PORT /dev/ttyUSB0)
#set(${PROJ_NAME}_SERIAL minicom)

file(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
    "include/*.hpp"
)
file(GLOB ${PROJ_NAME}_SRC_CODE
    "main.cpp"
    "src/*.c"
    "src/*.cpp"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

message(STATUS "INPUT_PORT: ${INPUT_PORT}")
message(STATUS "INPUT_SERIAL: ${INPUT_SERIAL}")

generate_arduino_firmware(${PROJ_NAME}
    HDRS ${${PROJ_NAME}_HEADERS}
    SRCS ${${PROJ_NAME}_SRC_CODE}
    BOARD_CPU ${BOARD_CPU}
    PORT /dev/ttyUSB0
    SERIAL minicom /dev/ttyUSB0
    )

cmake_minimum_required(VERSION 3.11)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../arduino-cmake/cmake/ArduinoToolchain.cmake)

message(STATUS "Using toolchain at: ${CMAKE_TOOLCHAIN_FILE}")

set(PROJ_NAME pipegochi)
project(${PROJ_NAME})

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

message(STATUS "ARDUINO_SDK_VERSION: ${ARDUINO_SDK_VERSION}")
message(STATUS "ARDUINO_PLATFORM_LIBRARIES_PATH: ${ARDUINO_PLATFORM_LIBRARIES_PATH}")
message(STATUS "INPUT_PORT: ${INPUT_PORT}")
message(STATUS "INPUT_SERIAL: ${INPUT_SERIAL}")

generate_arduino_firmware(${PROJ_NAME}
    HDRS ${${PROJ_NAME}_HEADERS}
    SRCS ${${PROJ_NAME}_SRC_CODE}
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )

# Hardware tester
add_subdirectory(testers)

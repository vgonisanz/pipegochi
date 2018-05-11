cmake_minimum_required(VERSION 3.11)

# use CMAKE_TOOLCHAIN_FILE option to specify another location
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino-cmake/cmake/ArduinoToolchain.cmake)

message(STATUS "Using toolchain at: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "Using arduino sdk at: ${ARDUINO_SDK_PATH}")
message(STATUS "ARDUINO_SDK_VERSION: ${ARDUINO_SDK_VERSION}")
message(STATUS "ARDUINO_PLATFORM_LIBRARIES_PATH: ${ARDUINO_PLATFORM_LIBRARIES_PATH}")
message(STATUS "INPUT_PORT: ${INPUT_PORT}")
message(STATUS "INPUT_SERIAL: ${INPUT_SERIAL}")

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

set(MAIN_PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${MAIN_PROJECT_PATH}/include)

# Dependencies
link_directories(${MAIN_PROJECT_PATH}/3rdParty/arduino/)

set(U8glib_RECURSE True) # U8glib have nested source code!

generate_arduino_firmware(${PROJ_NAME}
    HDRS ${${PROJ_NAME}_HEADERS}
    SRCS ${${PROJ_NAME}_SRC_CODE}
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )

# Hardware tester
add_subdirectory(testers)

cmake_minimum_required(VERSION 3.11)

# use CMAKE_TOOLCHAIN_FILE option to specify another location
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino-cmake/cmake/ArduinoToolchain.cmake)

set(PROJ_MAIN_NAME pipegochi-main)
project(${PROJ_MAIN_NAME})

# Configure main variables
set(${PROJ_MAIN_NAME}_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(3RDPARTY_PATH ${${PROJ_MAIN_NAME}_PATH}/3rdParty/arduino/)

# Project info
message(STATUS "Using toolchain at: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "Using arduino sdk at: ${ARDUINO_SDK_PATH}")
message(STATUS "ARDUINO_SDK_VERSION: ${ARDUINO_SDK_VERSION}")
message(STATUS "ARDUINO_PLATFORM_LIBRARIES_PATH: ${ARDUINO_PLATFORM_LIBRARIES_PATH}")
message(STATUS "Compiled at: ${${PROJ_MAIN_NAME}_PATH}")
message(STATUS "3rdParty at: ${3RDPARTY_PATH}")
message(STATUS "INPUT_PORT: ${INPUT_PORT}")
message(STATUS "INPUT_SERIAL: ${INPUT_SERIAL}")

# Dependencies
link_directories(${3RDPARTY_PATH})

set(U8glib_RECURSE True) # U8glib have nested source code!

# Pipegochi core
add_subdirectory(pipegochi)

# Hardware tester
add_subdirectory(samples)

cmake_minimum_required(VERSION 3.11)

set(PROJ_NAME u8gexe)
project(${PROJ_NAME})

include_directories(${${PROJ_MAIN_NAME}_PATH}/3rdParty/arduino/U8glib/cppsrc/)
include_directories(${${PROJ_MAIN_NAME}_PATH}/3rdParty/arduino/U8glib/csrc/)

generate_arduino_firmware(${PROJ_NAME}
    SRCS ${PROJ_NAME}.cpp
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )


set(PROJ_NAME adafruit)
project(${PROJ_NAME})

include_directories(${${PROJ_MAIN_NAME}_PATH}/3rdParty/arduino/Adafruit-GFX/)
include_directories(${${PROJ_MAIN_NAME}_PATH}/3rdParty/arduino/Adafruit_SSD1306/)

generate_arduino_firmware(${PROJ_NAME}
    SRCS ${PROJ_NAME}.cpp
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )

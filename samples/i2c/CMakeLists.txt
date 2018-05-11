cmake_minimum_required(VERSION 3.11)

set(PROJ_NAME scani2c)
project(${PROJ_NAME})

generate_arduino_firmware(${PROJ_NAME}
    SRCS ${PROJ_NAME}.cpp
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )

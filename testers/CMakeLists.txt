cmake_minimum_required(VERSION 3.11)

################################################################################
######################### CHECK THE BUTTONS SAMPLE #############################
################################################################################

project(buttons)

link_directories(${ARDUINO_PLATFORM_LIBRARIES_PATH}/Wire)

generate_arduino_firmware(buttons
    SRCS buttons.cpp
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )

################################################################################
######################### CHECK I2C DEVICES SAMPLE #############################
################################################################################
project(scani2c)

#link_directories(${ARDUINO_PLATFORM_LIBRARIES_PATH}/Wire)

generate_arduino_firmware(scani2c
    SRCS scani2c.cpp
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )

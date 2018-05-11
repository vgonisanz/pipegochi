set(PROJ_NAME pipegochi)
project(${PROJ_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
    "include/*.hpp"
)
file(GLOB ${PROJ_NAME}_SRC_CODE
    "main.cpp"
    "src/*.c"
    "src/*.cpp"
)

generate_arduino_firmware(${PROJ_NAME}
    HDRS ${${PROJ_NAME}_HEADERS}
    SRCS ${${PROJ_NAME}_SRC_CODE}
    BOARD_CPU ${BOARD_CPU}
    PORT ${INPUT_PORT}
    SERIAL minicom ${INPUT_SERIAL}
    )

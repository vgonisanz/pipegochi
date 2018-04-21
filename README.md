# Project

* Status: **WORKING ON PROJECT**

Tamagochi clone for Arduino. Tested on Arduino pro mini (atmega328p with 16 MHz) with Adafruit SSD1306 display.

# Dependencies

This code is compiled with CMake. It is needed to install in your compiler arduino-cmake

Clone into your compiler a valid [arduino-cmake](https://github.com/arduino-cmake/arduino-cmake). My code found it in a relative path. If you want to custom it, use ```CMAKE_TOOLCHAIN_FILE``` variable to point there.

* *NOTE:* arduino-cmake is based on [this](https://github.com/queezythegreat/arduino-cmake) project, but as you can see at [this](https://github.com/queezythegreat/arduino-cmake/issues/180) issue, **IT IS DEPRECATED**. Please don't use it because it won't run.

# Compile

To compile the code just:
```
mkdir build && cd build
cmake -DINPUT_BOARD=pro -DINPUT_PORT=/dev/ttyUSB0 -DINPUT_SERIAL=minicom -DBOARD_CPU=16MHzatmega328 ..
make
```

Add CMAKE_TOOLCHAIN_FILE if required:

```
cmake -DCMAKE_TOOLCHAIN_FILE=../path/to/toolchain/file.cmake -DINPUT_BOARD=pro -DINPUT_PORT=/dev/ttyUSB0 -DINPUT_SERIAL=minicom -DBOARD_CPU=16MHzatmega328 ..
```

# Upload

1. Push reset button.
1. Release reset button.
1. Execute immediately ```make upload```

* *NOTE*: Don't launch manually minicom if you want to upload a firmware image, because it will block the device and the image cannot be upload.

# Use UART

## Cmake way

Just execute:

```
make pipegochi-serial
```

* *NOTE:* This doesn't work for me. A problem with variables try to take ```/dev/modem``` instead ```/dev/ttyUSB0```

## Manual minicom

For me, this way works:

```
sudo minicom -D /dev/ttyUSB0 -b 9600
```

* *NOTE*: Disconnect it before upload a new firmware.

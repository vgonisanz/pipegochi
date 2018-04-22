# Project

* Status: **WORKING ON PROJECT**

Tamagochi clone for Arduino. Tested on Arduino pro mini (atmega328p with 16 MHz) with Adafruit SSD1306 display.

# Dependencies

## CMake compilation

This code is compiled with CMake. It is needed to install in your compiler arduino-cmake

Clone into your compiler a valid [arduino-cmake](https://github.com/arduino-cmake/arduino-cmake). My code found it in a relative path. If you want to custom it, use ```CMAKE_TOOLCHAIN_FILE``` variable to point there.

* *NOTE:* arduino-cmake is based on [this](https://github.com/queezythegreat/arduino-cmake) project, but as you can see at [this](https://github.com/queezythegreat/arduino-cmake/issues/180) issue, **IT IS DEPRECATED**. Please don't use it because it won't run.

## Arduino libraries

To manage the device, it is needed the device libraries. You can find the code:
* [Adafruit SSD1306 library repository](https://github.com/adafruit/Adafruit_SSD1306) or [last version download](https://github.com/adafruit/Adafruit_SSD1306/archive/master.zip).
* [Adafruit GFX library repository](https://github.com/adafruit/Adafruit-GFX-Library) or [last version download](https://github.com/adafruit/Adafruit-GFX-Library/archive/master.zip).

*NOTE:* For information on installing libraries, see: http://www.arduino.cc/en/Guide/Libraries.
*Summary:* Uncompress both zips and rename removing suffix into ```${USER_ARDUINO_PATH}/arduino/libraries``` path. Opening arduino IDE will found it on Examples > Custom examples.

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

# SS1306

SSD1306 chip have a driver to communicate in multiple ways including I2C, SPI and 8-bit parallel. In Dependencies section you can find a link to the source code.
Also, you can find more info about management at ```references/monochrome-oled-breakouts.pdf``` and into the datasheet ```references/SSD1306.pdf```.

* [ONLINE Device installation tutorial](https://learn.adafruit.com/monochrome-oled-breakouts)

## How create bitmaps

You can create bitmaps to display easily with the [LCD assistant software](http://en.radzio.dxp.pl/bitmap_converter/) in Windows (*Argh*) of ... .

1. Use a graphic editor like gimp and save it as Monochrome Bitmap (bmp) format.
... *TODO*

# Notes

This sofware idea was taken from [Tamaguino](https://alojzjakob.github.io/Tamaguino/). But I reimplemented everything from scratch, including compilation environment using CMake, and providing several source files instead only and sketch (ino) file. I thinks this was is more clear, scalable, and easier to learn and modify.

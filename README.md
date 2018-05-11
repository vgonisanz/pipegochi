# Project

* Status: **WORKING ON PROJECT**

Tamagochi clone for Arduino. Tested on Arduino pro mini (atmega328p with 16 MHz) with Adafruit SSD1306 display.

# Dependencies

Several submodules are used:

* **arduino-cmake**: To compile the source code.
* **U8glib**: To manage SSD1306 device and basic draw operations.
* **Adafruit_GFX/SSD1306**: This is used only for one example. Read SSD1306 section to have more info.
* **GLCD-BitmapConverter**: To convert bitmaps to c arrays automatically using python scripts.

*NOTE*: I recommend to clone with ```--recursive``` option to get all submodules automatically.

Arduino standards libraries are added directly with a working version:

* **Wire**: Arduino library that allows you to communicate with I2C and Two Wire Interface devices.
* **SPI**: This is required by Adafruit_GFX for some model. Not really required in this project. Sorry for overhead.

*NOTE*: I added directly because I didn't find a repository to add as a submodule and I didn't want manual dependencies.

## CMake compilation

I use arduino-cmake to ease programming new samples, and manage the source code out of the Arduino IDE. I think this is a more general way to do these kind of things.

* *NOTE:* arduino-cmake is based on [this](https://github.com/queezythegreat/arduino-cmake) project.
* *WARNING:* This project is based on queezythegreat repository. As you can see at [this](https://github.com/queezythegreat/arduino-cmake/issues/180) issue, **IT IS DEPRECATED**. Please don't use it because it won't run. This repository appear first if you google it.

### Submodule way

This code is compiled with CMake. It is needed to install in your compiler arduino-cmake.
I have added as submodule the toolchain at ```cmake```.

### General way

Clone into your compiler a valid [arduino-cmake](https://github.com/arduino-cmake/arduino-cmake). My code found it in a relative path as a submodule. If you already have it you can provide variable ```CMAKE_TOOLCHAIN_FILE``` instead adding that submodule.

## Arduino libraries

### Submodule way & direct way

* I have added as submodules all required drivers and library dependencies at ```3rdParty/arduino```.
* I have added arduino standard libraries dependencies at ```3rdParty/arduino``` directly.

### Default way

I don't use this way, but you have here some info.

* *Official reference:* For information on installing libraries, see: http://www.arduino.cc/en/Guide/Libraries.
* *Summary*: By default uncompress both zips and rename removing suffix into ```${USER_ARDUINO_PATH}/arduino/libraries``` path. Opening arduino IDE will found it on Examples > Custom examples.

# How to compile Compile

Assuming you are using all submodules, to compile the code run the following commands:
```
mkdir build && cd build
cmake -DINPUT_BOARD=pro -DINPUT_PORT=/dev/ttyUSB0 -DINPUT_SERIAL=minicom -DBOARD_CPU=16MHzatmega328 ..
make
```

Other tested boards, in example, nano:
```
cmake -DINPUT_BOARD=nano -DINPUT_PORT=/dev/ttyUSB0 -DINPUT_SERIAL=minicom -DBOARD_CPU=atmega328 ..
```

If you want to customize CMAKE_TOOLCHAIN_FILE option, you can run:

```
cmake -DCMAKE_TOOLCHAIN_FILE=../path/to/toolchain/file.cmake -DINPUT_BOARD=pro -DINPUT_PORT=/dev/ttyUSB0 -DINPUT_SERIAL=minicom -DBOARD_CPU=16MHzatmega328 ..
```

If you don't use submodules, please, install dependencies in arduino path before compiling!

# How to Upload into your device

1. Push reset button.
1. Release reset button.
1. Execute immediately ```make ${project}-upload```

* *NOTE*: Don't launch manually minicom if you want to upload a firmware image, because it will block the device and the image cannot be upload.
* *NOTE II*: ```make upload``` will try to upload all images. The device cannot get all :-)

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

# SSD1306

SSD1306 chip have a driver to communicate in multiple ways including I2C, SPI and 8-bit parallel. In Dependencies section you can find a link to the source code.
Also, you can find more info about management at ```references/monochrome-oled-breakouts.pdf``` and into the datasheet ```references/SSD1306.pdf```.

* [ONLINE Device installation tutorial](https://learn.adafruit.com/monochrome-oled-breakouts)

Exist several libraries to draw in this model:
* **Adafruit_SSD1306 + Adafruit_GFX**: I made a sample with this library, but it is too heavy for arduino pro mini. So I decided to avoid use it. Anyway, the sample
is into ```sample/display``` to be compiled and tested.
* **U8glib**: Simple and light.

## How create bitmaps

You can create bitmaps to display easily with the [LCD assistant software](http://en.radzio.dxp.pl/bitmap_converter/) in Windows (*Argh*) of ... .

1. Use a graphic editor like gimp and save it as Monochrome Bitmap (bmp) format.
... *TODO*

# Notes

* This sofware idea was taken from [Tamaguino](https://alojzjakob.github.io/Tamaguino/). But I reimplemented everything from scratch, including compilation environment using CMake, and providing several source files instead only and sketch (ino) file. I thinks this was is more clear, scalable, and easier to learn and modify.
* Script in python to convert bmp to c array is a fork from [GLCD-BitmapConverter](...). I made some changes to ease generation.

# TODO

* BitmapConverter create fork.
* CMake generate project assets using python script.
* Check why -DCMAKE_BUILD_TYPE=Release no impact in images.

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * config.h: I recommend to use this config file into ALL HEADERS at the beggining.
 * In this waym you will have defined arduino headers, log level, an others required
 * definitions.
 */

/* Use arduino headers */
#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

/*
 * Define log level
 * The logger.h cannot determine the user desire log level
 * You have to specify before include it.
 */
#define ___LOG_DEBUG

/*
 * Designed for Adafruit "SSD1306_128_64" - 128x64 pixel display.
 * The library cannot determine the screen size via software.
 * You have to specify it in the header file.
 */
//#define SSD1306_128_64

#endif /* __CONFIG_H */

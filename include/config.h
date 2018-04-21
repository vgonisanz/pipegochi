#ifndef __CONFIG_H
#define __CONFIG_H

/* Use arduino headers */
#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

/* Define log level */
#define ___LOG_DEBUG

#endif /* __CONFIG_H */

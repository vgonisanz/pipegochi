#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <util/delay.h>
#include <stdio.h>

/* Allow this level of LOGs & identify main with LOG_TAG */
#define ___LOG_DEBUG
#include "include/logger.h"
#define LOG_TAG "main"

#include "led.h"
#include "tamagochi.h"
#include "interrupts.h"

Tamagochi puppy;

static void infinite_loop()
{
    while(true)
    {
        LOGD("loop");
        _delay_ms(1000);
        led::turn_switch();
        puppy.update();
    }
}

/* Entry point: Always called first */
void setup()
{
    configure_uart(9600);       /* Force initialize UART before using LOGS in logger!!! */
    initialize_interrupts();    /* Set up time running */
    initialize_time(0, 0);
    led::initialize();
    led::turn_on();
    _delay_ms(500);
    LOGD("setup Aw right");
    led::turn_off();
}

/* Post setup function */
void loop()
{
    infinite_loop();
}

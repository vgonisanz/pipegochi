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

static void print_date()
{
    time_t rightnow = time(0);
    struct tm *is_now = localtime(&rightnow);
    LOGD("Data: %d", rightnow);
}

/*
 * Mmmmh, something doesn't update time
 * http://www.nongnu.org/avr-libc/user-manual/group__avr__time.html
 */
static void initialize_time()
{
    set_zone(0);
    //set_dst();
    set_system_time(0);
}

static void infinite_loop()
{
    while(true)
    {
        LOGD("loop");
        _delay_ms(1000);
        led::turn_switch();
        print_date();
    }
}

/* Entry point: Always called first */
void setup()
{
    led::initialize();
    led::turn_on();
    configure_uart();       /* Force initialize UART before using LOGS in logger!!! */
    _delay_ms(500);
    LOGD("setup Aw right");
    led::turn_off();
}

/* Post setup function */
void loop()
{
    infinite_loop();
}

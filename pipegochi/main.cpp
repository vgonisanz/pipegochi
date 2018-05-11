#include "config.h"

#define LOG_TAG "main"
#include "logger.h"

#include "uart.h"
#include "interrupts.h"
#include "clock.h"
#include "led.h"
#include "tamagochi.h"

Tamagochi puppy;
Clock userClock;

static void print_version()
{
    LOGI("Version: %d.%d.%d", __VERSION_MAJOR, __VERSION_MINOR, __VERSION_SUB_MINOR);
}

static void infinite_loop()
{
    while(true)
    {
        puppy.update(); /* Try to update */
        _delay_ms(APP_SLEEP_PERIOD_IN_MS);
    }
}

/* Entry point: Always called first */
void setup()
{
    led::initialize();
    led::turn_on();

    configure_uart(9600);       /* First to do, force initialize UART before using LOGS in logger!!! */
    print_version();
    Clock::printCompileDate();       /* NO PRINT TODO problem with logger file parse */

    LOGI("Configuring app...");
    userClock.setTime(0, 0);
    initialize_interrupts();    /* Set up time running */

    led::turn_off();
}

/* Post setup function */
void loop()
{
    LOGI("Start working!");
    infinite_loop();
}

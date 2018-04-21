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

#include <avr/interrupt.h>
#include <util/atomic.h>

/* THIS NOT WORK RIGHT NOW */
ISR(TIMER1_CAPT_vect, ISR_NAKED)
{
    LOGD("TIMER1_CAPT_vect");
    system_tick();
    reti(); /* Last ISR_NAKED routine cmd */
}

/*
 * Interrupt each 1 Hz set at initialize_interrupts.
 * Update system ticks.
 *
 * Note: Using a 'Naked' ISR, avoiding the cost of saving
 * and restoring all the cpu registers.
 */
ISR(TIMER1_COMPA_vect, ISR_NAKED)
{
    //LOGD("TIMER1_COMPA_vect");
    system_tick();  /* Update system tick with an interrupt with 1 Hz, feeding time */
    reti(); /* Last ISR_NAKED routine cmd */
}

/*
 * Important:
 * The application must initialize the time system to get correct time.
 * System time is maintained by calling the function system_tick() at one second intervals.
 *
 * Time reference:
 * http://www.nongnu.org/avr-libc/user-manual/group__avr__time.html
 *
 * Interrupts reference to update time:
 * https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html
 */
static void initialize_time()
{
    LOGD("Date: %d, Time: %d", __DATE__, __TIME__); /* Compile time */
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
    }
}

static void initialize_interrupts()
{
    cli();  /* set Global Interrupt Disabled */

    /* Set up timer1 interrupt at 1Hz */
    TCCR1A = 0; // set entire TCCR1A & TCCR1B register to 0
    TCCR1B = 0;
    TCNT1  = 0; // Initialize counter value to 0

    /* Set compare match register for 1hz increments */
    OCR1A = 15624;  // = (16*10^6) / (1*1024) - 1 (must be < 65536)

    TCCR1B |= (1 << WGM12); /* turn on CTC mode */
    TCCR1B |= (1 << CS12) | (1 << CS10);    /* Set CS12 and CS10 bits for 1024 prescaler */
    TIMSK1 |= (1 << OCIE1A);    /* Enable timer compare interrupt */

    sei();  /* set Global Interrupt Enable */
}
/* Entry point: Always called first */
void setup()
{
    configure_uart(9600);       /* Force initialize UART before using LOGS in logger!!! */
    initialize_interrupts();    /* Set up time running */
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

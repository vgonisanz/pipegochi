#pragma once

#include "Arduino.h"
#include <time.h>
/*
 * Initialize interrupts for date/time using timer 1 at 1 Hz
 *
 * Interrupts reference to update time:
 * https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html
 */
void initialize_interrupts();

/*
 * Important:
 * The application must initialize the time system to get correct time.
 * System time is maintained by calling the function system_tick() at one second intervals.
 *
 * Time reference:
 * http://www.nongnu.org/avr-libc/user-manual/group__avr__time.html
 */
void initialize_time(int32_t zone, time_t timestamp);

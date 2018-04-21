#ifndef __CLOCK_H
#define __CLOCK_H

#include "config.h"
#include <time.h>

/*
 * Important:
 * The application must initialize the time system to get correct time.
 * System time is maintained by calling the function system_tick() at one second intervals.
 *
 * Time reference:
 * http://www.nongnu.org/avr-libc/user-manual/group__avr__time.html
 */
void initialize_time(int32_t zone, time_t timestamp);

void print_compile_date();

#endif /* __CLOCK_H */

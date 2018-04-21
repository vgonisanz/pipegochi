#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#include "Arduino.h"

/*
 * Initialize interrupts for date/time using timer 1 at 1 Hz
 *
 * Interrupts reference to update time:
 * https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html
 */
void initialize_interrupts();

#endif /* __INTERRUPTS_H */

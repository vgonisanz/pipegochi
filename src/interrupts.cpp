#include "interrupts.h"

#include <avr/interrupt.h>
#include <time.h>           /* Required for system_tick */

/*
 * Interrupt each 1 Hz set at initialize_interrupts.
 * Update system ticks.
 *
 * Note: Using a 'Naked' ISR, avoiding the cost of saving
 * and restoring all the cpu registers.
 */
ISR(TIMER1_COMPA_vect, ISR_NAKED)
{
    system_tick();  /* Update system tick with an interrupt with 1 Hz, feeding time */
    reti(); /* Last ISR_NAKED routine cmd */
}

void initialize_interrupts()
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

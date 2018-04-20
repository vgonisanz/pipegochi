#pragma once

namespace led
{

/* Set up digital pin LED_BUILTIN as an output. */
void initialize();

/* Turn the LED on (HIGH is the voltage level) */
void turn_on();

/* Turn the LED off by making the voltage LOW */
void turn_off();

/* Turn the LED on if off and viceversa */
void turn_switch();

} /* namespace led */

#include "led.h"

namespace led
{

const int32_t LED_ID = LED_BUILTIN;

void initialize()
{
    pinMode(LED_ID, OUTPUT);
}
void turn_on()
{
    digitalWrite(LED_ID, HIGH);
}

void turn_off()
{
    digitalWrite(LED_ID, LOW);
}

void turn_switch()
{
    bool result = digitalRead(LED_ID);
    digitalWrite(LED_ID, !result);
}

} /* namespace led */

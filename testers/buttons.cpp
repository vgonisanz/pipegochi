#include "Arduino.h"
#include <Wire.h>

/*
 * Exist 2 way to use buttons, connecting a resistor or not:
 *      WITH RESISTOR: PUSH button when HIGH, input mode shall be INPUT
 *      WITHOUT RESISTOR: PUSH button when LOW, input mode shall be INPUT_PULLUP
 *
 *      define/undefine WITH_RESISTOR to change configuration
 */
#define WITH_RESISTOR
#undef WITH_RESISTOR

#ifdef WITH_RESISTOR
#   define INPUT_MODE INPUT
#   define BUTTON_PUSH HIGH
#   define BUTTON_UNPUSH LOW
#else
#   define INPUT_MODE INPUT_PULLUP
#   define BUTTON_PUSH LOW
#   define BUTTON_UNPUSH HIGH
#endif

/* Configuration */
const uint8_t PIN_LED =  13;      /* Led ID to switch */
const uint8_t PIN_BUTTON_1 = 2;   /* Connect a button in point 2, 3 and 4 */
const uint8_t PIN_BUTTON_2 = 3;
const uint8_t PIN_BUTTON_3 = 4;
const uint16_t BLINK_DELAY_IN_MS = 300;
const uint16_t LOOP_DELAY_IN_MS = 3000;     /* 3s between loops */

/* Check if a button is pushed */
bool is_button_pushed(uint8_t button_id)
{
    return (BUTTON_PUSH == digitalRead(button_id));
}

/* Blink n times the LED */
void n_blink(uint8_t times)
{
    while(times > 0)
    {
        digitalWrite(PIN_LED, HIGH);
        delay(BLINK_DELAY_IN_MS);
        digitalWrite(PIN_LED, LOW);
        delay(BLINK_DELAY_IN_MS);
        times--;
    }
}

void setup(void)
{
    Serial.begin(9600);
    Serial.println("Welcome to buttons sample...\n");
    Serial.print("The led configured have ID: ");
    Serial.println(PIN_LED, DEC);
    Serial.print("The buttons configured have IDs: ");
    Serial.print(PIN_BUTTON_1, DEC);
    Serial.print(", ");
    Serial.print(PIN_BUTTON_2, DEC);
    Serial.print(", ");
    Serial.println(PIN_BUTTON_3, DEC);

    /* Set up pins */
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_BUTTON_1, INPUT_MODE);
    pinMode(PIN_BUTTON_2, INPUT_MODE);
    pinMode(PIN_BUTTON_3, INPUT_MODE);
}

void loop(void)
{
    Serial.println("Checking buttons...");
    if (is_button_pushed(PIN_BUTTON_1))
    {
        Serial.print("Button 1 is pressed, blinking 1 time... ");
        n_blink(1);
        Serial.println("done.");
    }
    else
    {
        Serial.println("Button 1 is NOT pressed.");
    }

    if (is_button_pushed(PIN_BUTTON_2))
    {
        Serial.print("Button 2 is pressed, blinking 2 time... ");
        n_blink(2);
        Serial.println("done.");
    }
    else
    {
        Serial.println("Button 2 is NOT pressed.");
    }

    if (is_button_pushed(PIN_BUTTON_3))
    {
        Serial.print("Button 3 is pressed, blinking 3 time... ");
        n_blink(3);
        Serial.println("done.");
    }
    else
    {
        Serial.println("Button 3 is NOT pressed.");
    }
    delay(LOOP_DELAY_IN_MS);
}

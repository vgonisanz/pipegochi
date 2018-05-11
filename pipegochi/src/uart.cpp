#include "uart.h"

#define LOG_TAG "uart"
#include "logger.h"

FILE uartout = { 0 };    /* UART buffering FILE */

int uart_putchar(char c, FILE *stream)
{
   if( c == '\n' )
      Serial.write('\r');
   Serial.write(c);
   return 0 ;
}

void configure_uart(int32_t rate)
{
    Serial.begin(rate);
    fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &uartout;
}

#ifndef __UART_H
#define __UART_H

#include "config.h"

/*
 * uart_putchar: char output function for printf
 */
int uart_putchar(char c, FILE *stream);

/*
 * configure_uart: Set up UART rate and put file stream.
 * Importante note: Call this method before start using
 * the logs to be printed into UART.
 */
void configure_uart(int32_t rate);

#endif /* __UART_H */

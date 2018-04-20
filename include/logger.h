#pragma once

/* UART buffering */
static FILE uartout = { 0 };   // FILE struct

/* uart_putchar - char output function for printf */
static inline int uart_putchar(char c, FILE *stream)
{
   if( c == '\n' )
      Serial.write('\r');
   Serial.write(c) ;
   return 0 ;
}

/* Call this method before start using */
static inline void configure_uart()
{
    Serial.begin(9600);
    fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    printf("UART stdout configured!\n");
}

/* Initialize logger */
#if defined(___LOG_DEBUG)


#endif

#if defined(___LOG_DEBUG)
#include <stdio.h>
#include <time.h>


/* Be careful with multithreading!!! */
static char buff[100];
static struct tm *sTm;
static time_t now;
#		define PRINT_TIME {now = time(0); sTm = localtime(&now); strftime(buff, sizeof(buff), "[%Y-%m-%d %H:%M:%M]", sTm); fprintf(&uartout, "%s ", buff); }
#		define LOGV(...) {PRINT_TIME fprintf(&uartout, "[V][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#		define LOGD(...) {PRINT_TIME fprintf(&uartout, "[D][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#		define LOGI(...) {PRINT_TIME fprintf(&uartout, "[I][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#		define LOGW(...) {PRINT_TIME fprintf(&uartout, "[W][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#       define LOGE(...) {PRINT_TIME fprintf(&uartout, "[E][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}

//#elif defined(___LOG_INFO)
//#elif defined(___LOG_WARNING)
//#elif defined(___LOG_ERROR)
#else
// NO LOGS
#  define LOGV(...)
#  define LOGD(...)
#  define LOGI(...)
#  define LOGW(...)
#  define LOGE(...)
#endif

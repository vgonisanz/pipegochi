#pragma once

#include "Arduino.h"
extern FILE uartout;

/* UART is needed to send the logger info */
//#include "uart.h"

/*
 * LOG Header to ease printing with style.
 *
 * Log levels: ___LOG_DEBUG, ___LOG_INFO, ___LOG_VERBOSE, ___LOG_WARNING, ___LOG_ERROR
 * Only one log level shall be defined, at least once, before including "logger.h"
 * Each cpp shall define LOG_TAG in order to print a reference.
 * No define LOG_TAG in a header!
 *      I.e:    #define LOG_TAG "main"
 *              #define LOG_TAG __FILE__
 * Each level print it self and the rest until the end of the line.
 *      I.e:    ___LOG_DEBUG : Print everything, ___LOG_ERROR : Only errors.
 *
 * Standard Predefined Macros Reference:
 * https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html
 */

#if !defined(LOG_TAG)
#pragma message("logger.h included without define LOG_TAG before!")
#endif


/* Initialize logger */
#if defined(___LOG_DEBUG) || defined(___LOG_INFO) || defined(___LOG_VERBOSE) || defined(___LOG_WARNING) || defined(___LOG_ERROR)
#   include <stdio.h>
#   include <time.h>
#   include <util/eu_dst.h>
    /* Be careful with multithreading!!! */
    char buff[100];
    struct tm *sTm;
    time_t now;

#   define PRINT_TIME {now = time(0); sTm = localtime(&now); strftime(buff, sizeof(buff), "[%Y-%m-%d %H:%M:%S]", sTm); fprintf(&uartout, "%s ", buff); }
#endif

/* Define all logs as empty, they will be undef if no needed depending log level */
#  define LOGV(...)
#  define LOGD(...)
#  define LOGI(...)
#  define LOGW(...)
#  define LOGE(...)

#if defined(___LOG_DEBUG) || defined(___LOG_INFO) || defined(___LOG_VERBOSE) || defined(___LOG_WARNING) || defined(___LOG_ERROR)
#   undef LOGE
#   define LOGE(...) {PRINT_TIME fprintf(&uartout, "[E][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#endif

#if defined(___LOG_DEBUG) || defined(___LOG_INFO) || defined(___LOG_VERBOSE) || defined(___LOG_WARNING)
#   undef LOGW
#   define LOGW(...) {PRINT_TIME fprintf(&uartout, "[W][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#endif

#if defined(___LOG_DEBUG) || defined(___LOG_INFO) || defined(___LOG_VERBOSE)
#   undef LOGV
#	define LOGV(...) {PRINT_TIME fprintf(&uartout, "[V][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#endif

#if defined(___LOG_DEBUG) || defined(___LOG_INFO)
#   undef LOGI
#	define LOGI(...) {PRINT_TIME fprintf(&uartout, "[I][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#endif

#if defined(___LOG_DEBUG)
#   undef LOGD
#	define LOGD(...) {PRINT_TIME fprintf(&uartout, "[D][%s] ", LOG_TAG); fprintf(&uartout, __VA_ARGS__); fprintf(&uartout, "\n");}
#endif

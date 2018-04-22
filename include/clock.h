#ifndef __CLOCK_H
#define __CLOCK_H

#include "config.h"
#include <time.h>

/* Clock: Class to configure device, and manage time.
 * This require user
 * input to configure it
 */
 class Clock
 {
 public:
     Clock();
     ~Clock();

     /*
      * Important:
      * The application must initialize the time system to get correct time.
      * System time is maintained by calling the function system_tick() at one second intervals.
      *
      * Time reference:
      * http://www.nongnu.org/avr-libc/user-manual/group__avr__time.html
      */
     void setTime(int32_t zone, time_t timestamp);

     /*
      * \brief start: Start a new game, generating a new Tamagochi and initializing
      * all variables to default.
      */
     void addHour(int8_t hours);

     /*
      * \brief start: Start a new game, generating a new Tamagochi and initializing
      * all variables to default.
      */
     void addMinute(int8_t minutes);

     /*
      * \brief start: Start a new game, generating a new Tamagochi and initializing
      * all variables to default.
      */
     static void printCompileDate();
 private:
     uint8_t _hour;
     uint8_t _minute;

     /*
      * \brief updateClock: get current date and update with user hour and minute
      */
     void updateClock();
 };

#endif /* __CLOCK_H */

#include "clock.h"

#define LOG_TAG "clock"
#include "logger.h"

/* PUBLIC */
Clock::Clock():
_hour(0),
_minute(0)
{

}

Clock::~Clock()
{

}

void Clock::addHour(int8_t hours)
{
    _hour = _hour + hours;
}

void Clock::addMinute(int8_t minutes)
{
    _minute = _minute + minutes;
}

void Clock::setTime(int32_t zone, time_t timestamp)
{
    set_zone(zone);
    set_system_time(timestamp);
}

void Clock::printCompileDate()
{
    LOGI("Compiled at %s on %s", __TIME__, __DATE__);   /* compile time */
}

/* PRIVATE */
void Clock::updateClock()
{
    //struct tm * date = gmtime(time(0));
}

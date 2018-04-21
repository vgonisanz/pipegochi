#include "clock.h"

#define LOG_TAG "clock"
#include "logger.h"

void initialize_time(int32_t zone, time_t timestamp)
{
    //LOGD("Date: %d, Time: %d", __DATE__, __TIME__); /* Compile time */
    set_zone(0);
    //set_dst();
    set_system_time(0);
}

void print_compile_date()
{
    LOGI("Compiled at %s on %s", __TIME__, __DATE__);
}

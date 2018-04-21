#include "tamagochi.h"

#define LOG_TAG "tamagochi"
#include "logger.h"

Tamagochi::Tamagochi()
{

}

Tamagochi::~Tamagochi()
{

}

void Tamagochi::update()
{
    //LOGD("update"); /* No work check why */
    Serial.println("update");
}

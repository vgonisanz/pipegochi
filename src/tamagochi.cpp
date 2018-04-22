#include "tamagochi.h"

#define LOG_TAG "tamagochi"
#include "logger.h"

Tamagochi::Tamagochi():
_hunger(100),
_happiness(50),
_health(100),
_discipline(10),
_weight(1),
_age(0)
{

}

Tamagochi::~Tamagochi()
{

}

void Tamagochi::printStatus()
{
    /* Check why is failing */
    //LOGI("Pet status - Hunger: %u, Happiness: %u, Health: %u, Discipline: %u, Weight: %u, Age: %u",
    //                    this->_hunger, this->_happiness, this->_health, this->_discipline, this->_weight, this->_age);
    LOGI("Pet status:");
    LOGR("-------------------------------------");
    LOGR("* Hunger:     %u", this->_hunger);
    LOGR("* Happiness:  %u", this->_happiness);
    LOGR("* Health:     %u", this->_health);
    LOGR("* Discipline: %u", this->_discipline);
    LOGR("* Weight:     %u", this->_weight);
    LOGR("* Age:        %u", this->_age);
    LOGR("-------------------------------------");
}

void Tamagochi::update()
{
    LOGD("Tamagochi update");
}

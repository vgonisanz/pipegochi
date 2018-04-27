#include "tamagochi.h"

#define LOG_TAG "tamagochi"
#include "logger.h"

#include <time.h>

/* PUBLIC */

Tamagochi::Tamagochi():
_status(TamagochiStatus()),
_config(TamagochiConfig((uint32_t)TAMAGOCHI_UPDATE_IN_S))
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
    LOGR("* Hunger:     %u", this->_status.hunger);
    LOGR("* Happiness:  %u", this->_status.happiness);
    LOGR("* Health:     %u", this->_status.health);
    LOGR("* Discipline: %u", this->_status.discipline);
    LOGR("* Weight:     %u", this->_status.weight);
    LOGR("* Age:        %u", this->_status.age);
    LOGR("-------------------------------------");
}

void Tamagochi::start(TamagochiConfig config)
{
    LOGI("New Tamagochi is born");
    _config = config;
    setLastUpdate();
}

void Tamagochi::update()
{
    if(isNeededToUpdate())
    {
        updateHunger();
        updateHealth();
        updateHappiness();
        updateDiscipline();
        setLastUpdate();
        printStatus();
    }
}

/* PRIVATE */
bool Tamagochi::isNeededToUpdate()
{
    uint32_t difference = difftime(time(0), _status.lastUpdate);
    return (difference > _config.updatePeriod);
}

void Tamagochi::updateHunger()
{
    _status.hunger -= 1;
}

void Tamagochi::updateDiscipline()
{
    _status.discipline -= 1;
}

void Tamagochi::updateHealth()
{
    uint32_t minutesWithoutPlay = 0; /* TODO */
    uint32_t playFactor = minutesWithoutPlay * 10;
    uint32_t poopFactor = _status.poops * 10;
    _status.health = _status.health - playFactor - poopFactor;
}

void Tamagochi::updateHappiness()
{
    _status.happiness -= 1;
}

void Tamagochi::updateState()
{
    /* Too much poops? go sick */

    /* Time to sleep/wake up? */
}

void Tamagochi::setLastUpdate()
{
    _status.lastUpdate = time(0);   /* Get current time */
}

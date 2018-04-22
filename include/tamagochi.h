#ifndef __TAMAGOCHI_H
#define __TAMAGOCHI_H

#include "config.h"

struct TamagochiStatus
{
    uint32_t lastUpdate;
    uint8_t hunger;
    uint8_t happiness;
    uint8_t health;
    uint8_t discipline;
    uint8_t weight;
    uint8_t age;
    uint8_t poops;

    bool isDead;

    TamagochiStatus():
    lastUpdate(0),
    hunger(100),
    happiness(50),
    health(100),
    discipline(10),
    weight(1),
    age(0),
    poops(0),
    isDead(true) { }
};

struct TamagochiConfig
{
    uint32_t updatePeriod;  /* Update period on seconds */

    TamagochiConfig(uint32_t period):
    updatePeriod(period) { }
};

class Tamagochi
{
public:
    Tamagochi();
    ~Tamagochi();

    /*
     * start: Start a new game, generating a new Tamagochi and initializing
     * all variables to default.
     */
    void start(TamagochiConfig config);
    /*
     * update: Call update regularly. This functions will
     * update Tamagochi properties if enough time has passed.
     */
    void update();

    void printStatus();
private:
    TamagochiStatus _status;
    TamagochiConfig _config;

    /* Check if is needed to update the Tamagochi values */
    bool isNeededToUpdate();

    void updateHealth();
    void updateHappiness();
    void updateDiscipline();
    
    /* Update last time was updated */
    void setLastUpdate();
};

#endif /* __TAMAGOCHI_H */

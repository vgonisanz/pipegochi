#ifndef __TAMAGOCHI_H
#define __TAMAGOCHI_H

#include "config.h"

enum TamagochiStates
{
    T_NORMAL = 0,   /* Awake and living */
    T_EGG,          /* Tamagochi has not born */
    T_PLAYING,      /* Tamagochi is playing with you right now */
    T_SLEEPING,     /* Tamagochi is sleeping now */
    T_DEAD,         /* :-( Oh no! */
    T_ANGEL,        /* You win, Tamagochi became an angel */
    T_EVIL          /* You lose, you are a bad father/mother */
};

struct TamagochiStatus
{
    uint32_t lastUpdate;
    uint32_t lastPlay;
    uint8_t hunger;
    uint8_t happiness;
    uint8_t health;
    uint8_t discipline;
    uint8_t weight;
    uint8_t age;
    uint8_t poops;
    TamagochiStates state;

    bool isSick;

    TamagochiStatus():
    lastUpdate(0),
    lastPlay(0),
    hunger(100),
    happiness(50),
    health(100),
    discipline(10),
    weight(1),
    age(0),
    poops(0),
    isSick(false),
    state(T_EGG) { }
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
     * \brief start: Start a new game, generating a new Tamagochi and initializing
     * all variables to default.
     */
    void start(TamagochiConfig config);
    /*
     * \brief update: Call update regularly. This functions will
     * update Tamagochi properties if enough time has passed.
     */
    void update();

    /*
     * \brief printStatus: Print into stdout current status.
     */
    void printStatus();
private:
    TamagochiStatus _status;
    TamagochiConfig _config;

    /* \brief isNeededToUpdate Check if is needed to update the Tamagochi values */
    bool isNeededToUpdate();

    /*
     * \brief updateHunger: Each update period, he is a little more hunger
     */
    void updateHunger();

    /*
     * \brief updateDiscipline: Check if you are a bad parent.
     */
    void updateDiscipline();

    /*
     * \brief updateHealth: Check if too much poop, or too much time without playing.
     */
    void updateHealth();

    /*
     * \brief updateHappiness: Each update period, he is a little more sad.
     */
    void updateHappiness();

    /*
     * \brief updateState: Check if Tamagochi need to go sleep, die, get sick...
     */
    void updateState();

    /* Update last time was updated */
    void setLastUpdate();
};

#endif /* __TAMAGOCHI_H */

#ifndef __TAMAGOCHI_H
#define __TAMAGOCHI_H

#include "config.h"

class Tamagochi
{
public:
    Tamagochi();
    ~Tamagochi();

    void printStatus();
    void update();
private:
    uint32_t _hunger;
    uint32_t _happiness;
    uint32_t _health;
    uint32_t _discipline;
    uint32_t _weight;
    uint32_t _age;
};

#endif /* __TAMAGOCHI_H */

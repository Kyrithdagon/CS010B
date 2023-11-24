#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <string>
#include <iostream>

using namespace std;

#include "Character.h"

class Warrior : public Character{
    public:
    Warrior(const string &name, double health, double attackStrength, const string &allegiance);
    void attack(Character &oppnent);

    private:
    string allegianceName;
};

#endif
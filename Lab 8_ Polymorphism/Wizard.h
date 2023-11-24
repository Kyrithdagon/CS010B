#ifndef __WIZARD_H__
#define __WIZARD_H__

#include <string>
#include <iostream>

using namespace std;

#include "Character.h"

class Wizard : public Character{
    public:
    Wizard(const string &name, double health, double attackStrength, int rank);
    void attack(Character &opponent);

    private:
    int rank;
};

#endif
#ifndef __ELF_H__
#define __ELF_H__

#include <string>
#include <iostream>

using namespace std;

#include "Character.h"

class Elf : public Character{
    public:
    Elf(const string &name, double health, double attackStrength, const string &family);
    void attack(Character &oppnent);

    private:
    string familyName;
};

#endif
#include <iostream>
#include <string>

using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrengh, const string &family)
    : Character(ELF, name, health, attackStrengh), familyName(family){
}

void Elf::attack(Character &opponent){
    if(opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.familyName == familyName){
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
        }
        else{
            double damageDealt = (health / MAX_HEALTH) * attackStrength;
            cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            opponent.damage(damageDealt);
            cout << opponent.getName() << " takes " << damageDealt << " damage." << endl;
        }
    }
    else{
        double damageDealt = (health / MAX_HEALTH) * attackStrength;
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        opponent.damage(damageDealt);
        cout << opponent.getName() << " takes " << damageDealt << " damage." << endl;
    }
}
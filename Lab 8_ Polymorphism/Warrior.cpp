#include <iostream>
#include <string>

using namespace std;

#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrengh, const string &allegiance)
    : Character(WARRIOR, name, health, attackStrengh), allegianceName(allegiance){
}

void Warrior::attack(Character &opponent){
    if(opponent.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.allegianceName == allegianceName){
            cout << "Warrior " << name << " does not attack Warrior " << opp.name << "." << endl;
            cout << "They share an allegiance with " << allegianceName << "." << endl;
        }
        else{
            double damageDealt = (health / MAX_HEALTH) * attackStrength;
            cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            opponent.damage(damageDealt);
            cout << opponent.getName() << " takes " << damageDealt << " damage." << endl;
        }
    }
    else{
        double damageDealt = (health / MAX_HEALTH) * attackStrength;
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        opponent.damage(damageDealt);
        cout << opponent.getName() << " takes " << damageDealt << " damage." << endl;
    }
}
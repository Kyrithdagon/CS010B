#include <iostream>
#include <string>

using namespace std;

#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrengh, int rank)
    : Character(WIZARD, name, health, attackStrengh), rank(rank){
}

void Wizard::attack(Character &opponent){
    double damageDealt;

    if(opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damageDealt = attackStrength * (1.0 * rank / opp.rank);
        cout << "Wizard " << name << " attacks " << opp.name << " --- POOF!!" << endl;
        opp.damage(damageDealt);
        cout << opp.name << " takes " << damageDealt << " damage." << endl;
    }
    else{
        damageDealt = attackStrength;
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        opponent.damage(damageDealt);
        cout << opponent.getName() << " takes " << damageDealt << " damage." << endl;
    }
}
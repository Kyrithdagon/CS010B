#include <string>

using namespace std;

#include "Character.h"

Character::Character(HeroType hType, const string &hName, double hHealth, double hAttackStrengh)
    : type(hType), name(hName), health(hHealth), attackStrength(hAttackStrengh){
}

HeroType Character::getType() const{
    return type;
}

const string & Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return static_cast<int>(health);
}

void Character::damage(double d){
    health = health - d;
}

bool Character::isAlive() const{
    return getHealth() > 0;
}
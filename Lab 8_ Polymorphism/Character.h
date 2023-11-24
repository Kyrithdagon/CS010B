#include <string>

using namespace std;

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum HeroType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
	HeroType type;
	string name;
	double health;
	double attackStrength;

 public:
 	Character(HeroType, const string &, double, double);

 	HeroType getType() const;

 	const string & getName() const;

 	int getHealth() const;
	 /* Returns the whole number of the health value (static_cast to int). */

 	void damage(double d);
	 /* Reduces health value by amount passed in. */

 	bool isAlive() const;
	/* Returns true if getHealth() returns an integer greater than 0, otherwise false */

 	virtual void attack(Character &) = 0;
 };

#endif
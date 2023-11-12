#include <iostream>

using namespace std;

#include "Distance.h"

Distance::Distance(){
    _feet = 0;
    _inches = 0.0;
}

Distance::Distance(unsigned ft, double in){
    _feet = ft;
    _inches = in;
    init();
}

Distance::Distance(double in){
    _feet = 0;
    _inches = in;
    init();
}

unsigned Distance::getFeet() const{
    return _feet;
}

double Distance::getInches() const{
    return _inches;
}

double Distance::distanceInInches() const{
    return (_inches + (_feet * 12));
}

double Distance::distanceInFeet() const{
    return (_feet + (_inches / 12));
}

double Distance::distanceInMeters() const{
    return (((_feet * 12) + _inches) * 0.0254);
}

Distance Distance::operator+(const Distance &rhs) const{
    return Distance(rhs._feet + _feet, rhs._inches + _inches);
}

Distance Distance::operator-(const Distance &rhs) const{
    Distance calc = Distance(distanceInInches() - rhs.distanceInInches());
    calc.init();
    return calc;
}

ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs._feet << "' " << rhs._inches << "\"";
    return out;
}

void Distance::init(){
    if(_feet < 0){
        _feet = _feet * -1;
    }
    if(_inches < 0){
        _inches = _inches * -1;
    }
    while(_inches >= 12){
        _inches = _inches - 12;
        _feet = _feet + 1;
    }
}
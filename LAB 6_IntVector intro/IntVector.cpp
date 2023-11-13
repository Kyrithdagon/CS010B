#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value){
    _size = capacity;
    _capacity = capacity;

    if(capacity == 0){
        _data = nullptr;
    }
    else{
        _data = new int[capacity];
        for(unsigned int i = 0; i < capacity; ++i){
            _data[i] = value;
        }
    }
}

IntVector::~IntVector(){
    delete[] _data;
}

unsigned IntVector::size() const{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    if(_size == 0){
        return true;
    }
    return false;
}

const int& IntVector::at(unsigned index) const{
    if((index < 0) || (index >= _size)){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

const int& IntVector::front() const{
    return _data[0];
}

const int& IntVector::back() const{
    return _data[_size - 1];
}
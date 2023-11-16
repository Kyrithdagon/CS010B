#include <iostream>
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
    delete _data;
}

unsigned IntVector::size() const{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    return _size == 0;
}

const int& IntVector::at(unsigned index) const{
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int& IntVector::at(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

void IntVector::insert(unsigned index, int value){
    // if(index >= _size){
    //     throw out_of_range("IntVector::insert_range_check");
    // }
    if(_capacity == 0){
        expand(1);
    }
    if(_capacity == _size){
        expand();
    }

    ++_size;
    if(index >= _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    else{
        for(unsigned int i = _size -1; i > index; --i){
            at(i) = at(i - 1);
        }
        at(index) = value;
    }
}

void IntVector::erase(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    for(unsigned int i = index; i < _size - 1; ++i){
        _data[i] = _data[i + 1];
    }
    --_size;
}

const int& IntVector::front() const{
    return _data[0];
}

int& IntVector::front(){
    return _data[0];
}

const int& IntVector::back() const{
    return _data[_size - 1];
}

int& IntVector::back(){
    return _data[_size - 1];
}

void IntVector::assign(unsigned n, int value){
    if(_capacity < n){
        if((_capacity != 0) && (n < _capacity * 2)){
            expand();
        }
        else{
            expand(n - _capacity);
        }
    }

    _size = n;
    for(unsigned int i = 0; i < n; ++i){
        _data[i] = value;
    }
}

void IntVector::push_back(int value){
    if(_size == _capacity){
        expand();
    }
    
    ++_size;
    _data[_size - 1] = value;
}

void IntVector::pop_back(){
    --_size;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned n, int value){
    if(_size > n){
        _size = n;
    }
    if(_capacity < n){
        if((_capacity != 0) && (n < _capacity * 2)){
            expand();
        }
        else{
            expand(n - _capacity);
        }
    }
    for(unsigned int i = _size; i < n; ++i){
        _data[i] = value;
    }
    _size = n;
}

void IntVector::reserve(unsigned n){
    if(n > _capacity){
        if(_capacity == 0){
            _capacity = n;
            return;
        }
        if(n >= _capacity){
            expand(n - _capacity);
        } //issues
    }
}

void IntVector::expand(){
    if(_capacity == 0){
        ++_capacity;
    }
    else{
        _capacity = _capacity * 2;
    }

    int *reallocate = _data;
    _data  = new int[_capacity];
    for(unsigned int i = 0; i < _size; ++i){
        _data[i] = reallocate[i];
    }
    delete[] reallocate;
}

void IntVector::expand(unsigned amount){
    _capacity = _capacity + amount;
    int *reallocate = _data;
    _data  = new int[_capacity];

    for(unsigned int i = 0; i < _size; ++i){
        _data[i] = reallocate[i];
    }
    delete[] reallocate;
}
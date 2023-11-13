#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
#include <vector>

using namespace std;

class IntVector {

  private:
    unsigned _size;
    unsigned _capacity;
    int *_data;

  public:
    IntVector(unsigned capacity = 0, int value = 0);
    
    ~IntVector();
    //The destructor is used to clean up (delete) any remaining dynamically-allocated 
    //memory. For this class, that will be the array pointed to by the int pointer named _data.
    
    unsigned size() const;
    //This function returns the current size (not the capacity) of the IntVector object,
    //which is the values stored in the _size member variable.

    unsigned capacity() const;
    //This function returns the current capacity (not the size) of the IntVector object,
    //which is the value stored in the _capacity member variable.

    bool empty() const;
    //Returns whether the IntVector is empty (_size is 0).

    const int & at(unsigned index) const;
    //This function will return the value stored in the element at the passed in index position. 
    //Your function should throw an outofrange exception if an invalid index is passed in. 
    //An invalid index is an index greater than or equal to the size.

    const int & front() const;
    //This function will return the value stored in the first element of the IntVector. 
    //This function does not check the size of the IntVector or the array. 
    //If the IntVector is empty then calling this function causes undefined behavior.

    const int & back() const;
    //This function will return the value stored in the last element of the IntVector. 
    //This function does not check the size of the IntVector or the array. 
    //If the IntVector is empty then calling this function causes undefined behavior.

};

#endif
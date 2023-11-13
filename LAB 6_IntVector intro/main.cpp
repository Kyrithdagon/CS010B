#include <iostream>
#include <vector>

using namespace std;

#include "IntVector.h"

int main() {
    IntVector test1;
    IntVector test2(5);
    IntVector test3(5, 10);

    cout << "Size of test 1: " << test1.size() << endl;
    cout << "Capacity of test 1: " << test1.capacity() << endl;
    cout << "Size of test 2: " << test2.size() << endl;
    cout << "Capacity of test 2: " << test2.capacity() << endl;
    cout << "Size of test 3: " << test3.size() << endl;
    cout << "Capacity of test 3: " << test3.capacity() << endl;

    if(test1.empty()){
        cout << "Correct" << endl;
    }
    else{
        cout << "Did not return correctly" << endl;
    }
    if(test3.empty()){
        cout << "Incorrect" << endl;
    }
    else{
        cout << "Returned correctly" << endl;
    }

    test3.at(6);

    test3.at(0);
    cout << test3.front() << endl;
    cout << test3.back() << endl;

    return 0;
}
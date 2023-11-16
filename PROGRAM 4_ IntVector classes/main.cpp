#include <iostream>

using namespace std;

#include "IntVector.h"

int main() {
    IntVector test1;
    IntVector test2(5);
    IntVector test3(5, 10);
    IntVector test4(10, 9); //to perform other tests after t3 is done

    // cout << "Size of test 1: " << test1.size() << endl;
    // cout << "Capacity of test 1: " << test1.capacity() << endl;
    // cout << "Size of test 2: " << test2.size() << endl;
    // cout << "Capacity of test 2: " << test2.capacity() << endl;
    // cout << "Size of test 3: " << test3.size() << endl;
    // cout << "Capacity of test 3: " << test3.capacity() << endl;

    // if(test1.empty()){
    //     cout << "Correct" << endl;
    // }
    // else{
    //     cout << "Did not return correctly" << endl;
    // }
    // if(test3.empty()){
    //     cout << "Incorrect" << endl;
    // }
    // else{
    //     cout << "Returned correctly" << endl;
    // }

    // test3.at(6);

    // test3.at(0);
    // cout << test3.front() << endl;
    // cout << test3.back() << endl;

    // test3.insert(1, 50);
    // test3.insert(3, 60);
    // for(int i = 0; i < test3.capacity(); ++i){
    //      cout << test3[i] << " "
    // }

    // test3.erase(1);
    // test3.erase(4);
    // for(int i = 0; i < test3.capacity(); ++i){
    //     cout << test3[i] << " "
    // }

    // test3.assign(9, 4);

    // test3.push_back(8);
    // cout << test3.back() << endl;
    // test3.pop_back();
    // cout << test3.back() << endl;

    // test3.clear();
    // cout << "Size of test 3: " << test3.size() << endl;
    // cout << "Capacity of test 3: " << test3.capacity() << endl;

    // test4.resize(5, 9);
    // cout << "Size of test 4: " << test4.size() << endl;
    // cout << "Capacity of test 4: " << test4.capacity() << endl;
    // test4.resize(11, 8);
    // cout << "Size of test 4: " << test4.size() << endl;
    // cout << "Capacity of test 4: " << test4.capacity() << endl;

    // test4.reserve(20);
    // cout << "Capacity of test 4: " << test4.capacity() << endl;
    
    return 0;
}
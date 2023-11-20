#include <iostream>
#include <vector> 
using namespace std;

/* Declare your function here */ 
void exactChange (int userTotal, vector<int>& coinVals);

int main() {
   int inputVal;
   vector<int> changeAmount(4); 
   
   /* Type your code here. Your code must call the function. */
   cin >> inputVal;

   if (inputVal == 0 || inputVal < 0){
       cout << "no change" << endl;
       return 0;
   } 
   exactChange (inputVal, changeAmount);

   if (changeAmount.at(0) > 0){
       cout << changeAmount.at(0);
       if (changeAmount.at(0) == 1){
           cout << " penny" << endl;
       }
       else {
           cout << " pennies" << endl;
       } 
   } 

   if (changeAmount.at(1) > 0){
       cout << changeAmount.at(1);
       if (changeAmount.at(1) == 1){
           cout << " nickel" << endl;
       }
       else {
           cout << " nickels" << endl;
       } 
   }  

   if (changeAmount.at(2) > 0){
       cout << changeAmount.at(2);
       if (changeAmount.at(2) == 1){
           cout << " dime" << endl;
       }
       else {
           cout << " dimes" << endl;
       } 
   }  

   if (changeAmount.at(3) > 0){
       cout << changeAmount.at(3);
       if (changeAmount.at(3) == 1){
           cout << " quarter" << endl;
       }
       else {
           cout << " quarters" << endl;
       } 
   }  

   return 0;
}

/* Implement your function here */ 
void exactChange (int userTotal, vector<int>& coinVals){
    int numQuarters, numDimes, numNickels, numPennies;

    numQuarters = userTotal / 25;
    userTotal -= numQuarters * 25;

    numDimes = userTotal / 10;
    userTotal -= numDimes * 10;

    numNickels = userTotal / 5;
    userTotal -= numNickels * 5;

    numPennies = userTotal;

    coinVals.at(0) = numPennies;
    coinVals.at(1) = numNickels;
    coinVals.at(2) = numDimes;
    coinVals.at(3) = numQuarters;
}
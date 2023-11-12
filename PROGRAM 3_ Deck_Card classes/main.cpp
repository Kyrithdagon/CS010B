#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
//bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
//ostream & operator<<(ostream &, const vector<Card> &);

int main() {
    srand(2222);
    string response;
    string fileName;
    int cardsPerHand;
    int numOfDeals;

    cout << "Do you want to output all hands to a file?(Yes/No)" << endl;
    if(response == "Yes"){
        cout << "Enter name of output file:" << endl;
        cin >> fileName;
    }
    
    cout << "Enter number of cards per hand: " << endl;
    cin >> cardsPerHand;

    cout << "Enter number of deals (simulations): " << endl;
    cin >> numOfDeals;

    cout << "Chances of receiving a pair in a hand of 6 cards is: 40%" << endl;

    return 0;
}

// bool hasPair(const vector<Card> &hand){
//     Card current;
//     if(current){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// ostream & operator<<(ostream &out, const vector<Card> &name){
//     if(Card.size() == 0){
//         return;
//     }
//     else{
//         out << name.rank << name.suit << ", ";
//     }
//     return out;
// }
#include <iostream>

using namespace std;

#include "Card.h"

Card::Card(){
    suit = 'c';
    rank = 2;
}

Card::Card(char cardSuit, int cardNum){
    suit = cardSuit;
    rank = cardNum;

    if((suit == 'C') || (suit == 'c')){
        suit = 'c'; 
    }
    else if((suit == 'D') || (suit == 'd')){
        suit = 'd'; 
    }
    else if((suit == 'H') || (suit == 'h')){
        suit = 'h'; 
    }
    else if((suit == 'S') || (suit == 's')){
        suit = 's'; 
    }
    else{
        suit = 'c';
    }

    if((rank < 1) || (rank > 13)){
        rank = 2;
    }
}

char Card::getSuit() const{
    return suit;
}

int Card::getRank() const{
    return rank;
}

ostream & operator<<(ostream &out, const Card &name){
    if(name.rank == 1){
        out << "Ace of ";
    }
    if(name.rank == 11){
        out << "Jack of ";
    }
    if(name.rank == 12){
        out << "Queen of ";
    }
    if(name.rank == 13){
        out << "King of ";
    }
    if((name.rank > 1 ) && (name.rank < 11)){
        out << name.rank << " of ";
    }
    if(name.suit == 'c'){
        out << "Clubs";
    }
    if(name.suit == 'd'){
        out << "Diamonds";
    }
    if(name.suit == 'h'){
        out << "Hearts";
    }
    if(name.suit == 's'){
        out << "Spades";
    }
    return out;
}
#include <iostream>
#include <algorithm>

using namespace std;

#include "Deck.h"

Deck::Deck(){
    char cardType = 's';
    for(int i = 52; i > 0; --i){
        theDeck.push_back(Card(cardType, ((i % 13) + 1)));
        if(i < 41){
            cardType = 'h';
        }
        if(i < 28){
            cardType = 'd';
        }
        if(i < 15){
            cardType = 'c';
        }
        // while (i < 13){
        //     cardType = 's';
        //     theDeck.push_back(Card(cardType, ((i % 13) + 1)));
        // }
        // while (i < 26){
        //     cardType = 'h';
        //     theDeck.push_back(Card(cardType, ((i % 13) + 1)));
        // }
        // while (i < 39){
        //     cardType = 'd';
        //     theDeck.push_back(Card(cardType, ((i % 13) + 1)));
        // }
        // while (i < 52){
        //     cardType = 'c';
        //     theDeck.push_back(Card(cardType, ((i % 13) + 1)));
        // }
    }
}

Card Deck::dealCard(){
    //Card playDeal = theDeck.at(theDeck.size() - 1);
    Card playDeal = theDeck.back();
    theDeck.pop_back();

    dealtCards.push_back(playDeal);
    return playDeal;
}

void Deck::shuffleDeck(){
    for(unsigned int i = 0; i < dealtCards.size(); ++i){
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();

    random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const{
    return theDeck.size();
}
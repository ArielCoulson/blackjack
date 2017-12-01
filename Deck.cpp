//
//  Deck.cpp
//  testing
//
//  Created by Ariel Coulson on 11/30/17.
//  Copyright © 2017 Ariel. All rights reserved.
//

#include <random>
using namespace std;
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include "Deck.h"

Deck::Deck(){
    for(int i = 1; i <= 13; i++){
        //places all of the cards into the deck
        for(int j = 0; j < 4; j++){
            deck.push_back(i);
        }
    }
}

void Deck::removeCard(int location){
    deck.erase(deck.begin() + location);
}

void Deck::clearAndReset(){
    deck.clear();
    for(int i = 1; i <= 13; i++){
        //places all of the cards into the deck
        for(int j = 0; j < 4; j++){
            deck.push_back(i);
        }
    }
}

int Deck::getCard(int location){
    int temp;
    temp = deck[location];
    return temp;
}

int Deck::deckSize(){
    int size = 0;
    size = static_cast<int>(deck.size());
    return size;
}
void Deck::printDeck(){
    for (vector<int>::const_iterator i = deck.begin(); i != deck.end(); ++i){
        //prints out the deck for rn.
        cout << *i;
    }
    
}

//
//  deck.h
//  testing
//
//  Created by Ariel Coulson on 11/30/17.
//  Copyright © 2017 Ariel. All rights reserved.
//

#ifndef Deck_h
#define Deck_h



class Deck{
private:
    vector<int> deck;
public:
    Deck();
    void removeCard(int);
    void printDeck();
    void clearAndReset();
};


#endif /* Deck_h */

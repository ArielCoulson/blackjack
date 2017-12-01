//
//  Hand.h
//  testing
//
//  Created by Ariel Coulson on 11/30/17.
//  Copyright © 2017 Ariel. All rights reserved.
//

#ifndef Hand_h
#define Hand_h


class Hand{
private:
    vector <int> theHand;
public:
    Hand();
    void addCard(int);
    void removeCard();
    void clearHand();
    void displayCards(int);
    void printHand();
    int sum();
    int getCard(int);
    bool hasBlackjack();
    int probSum();
};



#endif /* Hand_h */

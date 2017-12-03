//
//  Hand.h
//  testing
//Group 19!
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

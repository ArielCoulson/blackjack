//
//  deck.h
//  testing
//
//Group 19!
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
    int getCard(int);
    int deckSize();
};


#endif /* Deck_h */

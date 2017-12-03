//
//  Blackjack.h
//  testing
//
//  Created by Ariel Coulson on 11/30/17.
//  Copyright © 2017 Ariel. All rights reserved.
//

#ifndef Blackjack_h
#define Blackjack_h


#endif /* Blackjack_h */

void displayWelcome();
void initialMenu();
void secondMenu();
void Instructions();
void dealerWon();
void bust();
int isItValid(int);
int randomLocation(int);
void dealAndHit(Deck&, Hand&);
double probability(Hand&, Hand&, Deck&);
void displayWin();
void messagePrintHand(int, Hand&);
void splitHandTwo(Hand&, Hand&);
void playGame();
void playGameAI();

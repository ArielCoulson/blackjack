//
//  main.cpp
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
#include "Hand.h"
#include "Deck.h"
#include "Blackjack.h"


void displayWelcome(){
    string cardDisplay = "";
    
    
    
    string line0="   _______________________________________________________________________________________________";
    string line01="                                                                                                          ";
    string line1 ="\n\n  |  ██████╗ ██╗      █████╗  ██████╗██╗  ██╗     ██╗ █████╗  ██████╗██╗  ██╗     ██╗    ██████╗   |  \n";
    string line2 = "  |  ██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝     ██║██╔══██╗██╔════╝██║ ██╔╝    ███║   ██╔═████╗  |  \n";
    string line3 ="  |  ██████╔╝██║     ███████║██║     █████╔╝      ██║███████║██║     █████╔╝     ╚██║   ██║██╔██║  |  \n";
    string line4="  |  ██╔══██╗██║     ██╔══██║██║     ██╔═██╗ ██   ██║██╔══██║██║     ██╔═██╗      ██║   ████╔╝██║  |  \n";
    string line5="  |  ██████╔╝███████╗██║  ██║╚██████╗██║  ██╗╚█████╔╝██║  ██║╚██████╗██║  ██╗     ██║██╗╚██████╔╝  |  \n";
    string line6="  |  ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝     ╚═╝╚═╝ ╚═════╝   |  \n";
    string lineFinal="   _______________________________________________________________________________________________\n\n";
    
    
    cardDisplay = line0 +line1 + line2+line3+line4+line5+line6+lineFinal;
    cout<<cardDisplay;
    
    
}

void computerWon(){
    cout << "\nThe computer won! Judgement day is upon us. \n";
}

void initialMenu(){
    cout << "\nWelcome to Blackjack! Have fun playing!\n";
    cout << "\nWould you like to know the game instructions?\n"
    << "Enter the number value for your choice:\n"
    << "1. Yes \n"
    << "2. No \n";
}

void secondMenu(){
    cout << "\n\nEnter the number value for your choice:";
    cout <<"\n1. Start a game!";
    cout <<"\n2. Start a game alongside a computer!";
    cout <<"\n3. I would like to exit.";
}


void Instructions (){
    cout << "\tGoal: Reach 21 without going over.\n\n";
    cout << "\tThe Dealer (computer player) will be playing against you.\n\n";
    cout << "\tIf the Dealer busts (goes over), all players who\n";
    cout << "\thaven't busted will win.\n\n";
    cout << "\tIf the Dealer doesn't bust, the player(s)\n";
    cout << "\twho did not bust, will win, if their\n";
    cout << "\ttotal vlaue is greater than the Dealer's.\n\n";
    cout << "\tIf a player gets 21 and the Dealer doesn't\n";
    cout << "\tthe player is a winner.\n\n";
    cout << "\tIf the player and the Dealer both get 21\n";
    cout << "\tit is declared a push (tie).\n\n";
    
    //ADD that when playing a computer the computers hand is hidden.
    
    //NEEDS TO BE FORMATTEDD!!!! VVV
    cout << "\tPlease note: this version of blackjack only allows splits of the same exact card value in the first round\n";
}

void bust(){
    cout << "\nThat's a bust!\n";
}
void draw(){
    cout << "\nThat's a draw!\n";
}
void dealerWon(){
    string cardDisplay = "";
    //int  value = 1;
    string line1 ="\n\n██████╗ ███████╗ █████╗ ██╗     ███████╗██████╗     ██╗    ██╗ ██████╗ ███╗   ██╗    ██╗    \n";
    string line2 = "██╔══██╗██╔════╝██╔══██╗██║     ██╔════╝██╔══██╗    ██║    ██║██╔═══██╗████╗  ██║    ██║    \n";
    string line3 ="██║  ██║█████╗  ███████║██║     █████╗  ██████╔╝    ██║ █╗ ██║██║   ██║██╔██╗ ██║    ██║    \n";
    string line4="██║  ██║██╔══╝  ██╔══██║██║     ██╔══╝  ██╔══██╗    ██║███╗██║██║   ██║██║╚██╗██║    ╚═╝    \n";
    string line5="██████╔╝███████╗██║  ██║███████╗███████╗██║  ██║    ╚███╔███╔╝╚██████╔╝██║ ╚████║    ██╗    \n";
    string line6="╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝    ╚═╝    \n\n";
    
    
    cardDisplay = line1 + line2+line3+line4+line5+line6;
    cout<<cardDisplay;
}

void displayWin(){
    string cardDisplay = "";
    //int  value = 1;
    string line1 ="\n\n         _ _ _ _ ___ ___ _ _ _ ___ _ _ _________\n";
    string line2 = "        |A|Q|1|5|4  |7  |J|1|9|7  |A|K|2        |\n";
    string line3 ="        |@|@|@|@|@  |## |O|O|O|OO |+|+|+        |\n";
    string line4="        | | | | | @ |   | | | |   | | |    +    |\n";
    string line5="        | | | | |   | # | | | | O | | |         |\n";
    string line6="        | | | | | @ |   | | | |   | | |    +    |\n";
    string line7="        | | | | |   | # | | | | O | | |        +|\n";
    string line8="        | | | | |   |   | | | |   | | |        Z|\n";
    string line9="         ~ ~ ~ ~ ~~~ ~~~ ~ ~ ~ ~~~ ~ ~ ~~~~~~~~~\n";
    
    cardDisplay = line1 + line2+line3+line4+line5+line6+line7+line8+line9;
    cout<<cardDisplay;
    
    line1=" \n\n ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄       ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄      \n";
    line2="▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌     \n";
    line3="▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌     ▐░▌       ▐░▌ ▀▀▀▀█░█▀▀▀▀ ▐░▌░▌     ▐░▌     \n";
    line4="▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌       ▐░▌     ▐░▌     ▐░▌▐░▌    ▐░▌     \n";
    line5="▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌   ▄   ▐░▌     ▐░▌     ▐░▌ ▐░▌   ▐░▌     \n";
    line6="▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌  ▐░▌  ▐░▌     ▐░▌     ▐░▌  ▐░▌  ▐░▌     \n";
    line7=" ▀▀▀▀█░█▀▀▀▀ ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌ ▐░▌░▌ ▐░▌     ▐░▌     ▐░▌   ▐░▌ ▐░▌     \n";
    line8="     ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌▐░▌ ▐░▌▐░▌     ▐░▌     ▐░▌    ▐░▌▐░▌     \n";
    line9="     ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌░▌   ▐░▐░▌ ▄▄▄▄█░█▄▄▄▄ ▐░▌     ▐░▐░▌     \n";
    string line10="     ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌     \n";
    string line11="      ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀▀       ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀      \n";
    
    cardDisplay="";
    cardDisplay=line1+line2+line3+line4+line5+line6+line7+line8+line9+line10+line11;
    
    cout<<cardDisplay;
    
}

void messagePrintHand(int who, Hand & theHand){
    /*
     1. Players Hand
     2. Dealers Hand
     3. Computers Hand
     4. Players first split hand
     5. Players second split hand
     */
    
    //prints the proper message for the current hand.
    if(who == 1){
        cout << "\nThis is your hand: \n";
        theHand.printHand();
    }
    else if(who == 2){
        cout << "\nThis is the dealer's hand: \n";
        theHand.printHand();
    }
    else if(who == 3){
        cout << "\nThis is the AI's hand: \n";
        theHand.printHand();
    }
    else if(who == 4){
        cout << "\nThis is the player's first split hand: \n";
        theHand.printHand();
    }
}


int isItValid(int menu){
    /*
     if input is valid, it returns the users menu choice.
     */
    string choice = "";
    bool valid;
    valid = false;
    while(!valid){
        cout << "\nI choose: ";
        valid = true;
        cin >> choice;
        
        if(menu == 2){
            //first menu only has two options!
            if(choice.length() > 1 || (choice.at(0) != '1' && choice.at(0) != '2')){
                cin.clear();
                cin.ignore();
                cout << "Not a valid option, please try again.";
                valid = false;
            }
        }
        else if(menu == 3){
            //second menu currently has three options so:
            if(choice.length() > 1 || (choice.at(0) != '1' && choice.at(0) != '2' && choice.at(0) != '3')){
                cin.clear();
                cin.ignore();
                cout << "Not a valid option, please try again.";
                valid = false;
            }
        }
    }
    int instructionChoice = stoi(choice);
    return instructionChoice;
}

int randomLocation(int size){
    int location;
    location = rand() % size-1 + 1;
    return location;
}


void dealAndHit(Deck & tempDeck, Hand & currentHand){
    int location; //location to pull from deck
    int temp; //temp place holder for the varaible at a certain location of deck
    
    location = randomLocation(tempDeck.deckSize());
    temp = tempDeck.getCard(location);
    currentHand.addCard(temp);
    tempDeck.removeCard(location);
}


double probability(Hand & playerHand, Hand & dealerHand, Deck & tempDeck){
    //calculating special sum for probability
    //automatically takes Aces as ones.
    

    double probability = 0;
    double playerScore = playerHand.probSum();
    int count = 0;
    
    
    for (int i = 0; i < tempDeck.deckSize(); i++){
        if(tempDeck.getCard(i) > 10){
            if(playerScore + 10 <= 21){
                count++;
            }
        }
        else if ((playerScore + tempDeck.getCard(i) <= 21)) {
            count++;
        }
    }
    
    if (playerScore + dealerHand.getCard(1) <= 21) {
        //takes care of the hidden card, and adds it to the count.
        count++;
    }
    
    probability = (count * 100) / (tempDeck.deckSize() + 1);
    return probability;
}




void splitHandTwo(Hand & playerHand, Hand & splitHand){
    cout << "\nYou have decided to split your deck";
    splitHand.addCard(playerHand.getCard(1));
    playerHand.removeCard();
    cout << "\nThis is hand number 1:\n";
    playerHand.printHand();
    cout << "\nThis is hand number 2:\n";
    splitHand.printHand();
}


void playGame(){
    Hand playerHand;
    Hand dealerHand;
    Hand splitHand;
    Deck tempDeck;
    
    int number = 1;
    while(number < 5){
        if(number < 3){
            //deals the players two initial cards
            dealAndHit(tempDeck, playerHand);
        }
        else{
            //deals the dealers two initial cards
            dealAndHit(tempDeck, dealerHand);
        }
        number++;
    }
    
    cout << "\nThe two cards the dealer has dealt you are :\n";
    playerHand.printHand();
    if(playerHand.hasBlackjack() && !(dealerHand.hasBlackjack())){
        //may be want to reveal dealers hand too to show that they dont have blackjack??
        displayWin();
        return;
    }
    
    cout << "\nThe dealer has two cards. One is faced down, this is the other:\n";
    int tempCard = dealerHand.getCard(0);
    dealerHand.displayCards(tempCard);
    cout << "\n";
    dealerHand.displayCards(0);
    
    if(tempCard == 1 || tempCard >= 10){
        //dealer automatically checks for black jack w/ an ace or cards value 10.
        cout << "\nThe dealer is now checking to see if they have blackjack.\n";
        if(dealerHand.hasBlackjack()){
            dealerWon();
            return;
        }
        else{
            cout << "\nThe dealer does not have blackjack. You may continue playing.\n";
        }
    }
    
    //split logic:
    bool splitHappened = false;
    bool firstSplitDone = false; //false indicates that they have not busted or stopped hitting first deck;
    bool playerHandBust = false; //false indicates that first deck is not a bust
    bool splitHandBust = false; //false indicates the split deck is not a bust.
    
    int choice = 0;
    while(choice != 2){
        cout << "\nSelect the value for your next move:";
        cout << "\n1. Hit";
        cout << "\n2. Stay";
        
        //checks for valid input, as well as decides if the player needs option for a split
        if(playerHand.getCard(0) == playerHand.getCard(1) && !splitHappened){
            //a split has not occured. player has option to split or not.
            cout << "\n3. Split";
            probability(playerHand, dealerHand, tempDeck);
            choice = isItValid(3);
        }
        else{
            //this current hand has no split!
            if(splitHappened && !firstSplitDone){
                //gives you the probability of your second hand.
                probability(playerHand, dealerHand, tempDeck);
            }
            else if(splitHappened && firstSplitDone){
                //gives you the probability of your second hand.
                probability(splitHand, dealerHand, tempDeck);
            }
            else{
                //gives you the probability of your only hand.
                probability(playerHand, dealerHand, tempDeck);
            }
            choice = isItValid(2);
        }
        if(choice == 3){
            splitHappened = true;
            splitHandTwo(playerHand, splitHand);
        }
        else if(choice == 1 && !splitHappened){
            //indicates the player wants to hit; and they did not split their deck.
            dealAndHit(tempDeck, playerHand);
            
            cout << "\nThis is your current hand: \n";
            playerHand.printHand();
            if(playerHand.hasBlackjack()){
                dealerWon();
                return;
            }
            else if(playerHand.sum() > 21){
                bust();
                dealerWon();
                return;
            }
        }
        else if(choice == 1 && splitHappened){
            //indicates that the player wants to hit, and there has been a split
            if(!firstSplitDone){
                dealAndHit(tempDeck, playerHand);
                cout << "\nThis is the hand of your first split deck: ";
                playerHand.printHand();
                if(playerHand.sum() > 21){
                    bust();
                    cout << "\nNow we will work with your other split deck";
                    playerHandBust = true;
                    firstSplitDone = true;
                }
                else if(playerHand.sum() == 21){
                    displayWin();
                    firstSplitDone = true;
                    playerHandBust = true;
                }
            }
            else if(firstSplitDone){
                dealAndHit(tempDeck, splitHand);
                cout << "\nThis is the hand of your second split deck: ";
                if(splitHand.sum() > 21){
                    bust();
                    if(playerHandBust){
                        //their first deck was also a bust, dealer auto wins.
                        dealerWon();
                        return;
                    }
                    splitHandBust = true;
                }
                else if(splitHand.sum() == 21){
                    displayWin();
                    splitHandBust = true;
                }
            }
        }
        else if(choice == 2){
            if(splitHappened && !firstSplitDone){
                firstSplitDone = true;
                choice = 0;
            }
        }
    }
    
    if(!splitHappened){
        cout << "\nYour final hand is: \n";
        playerHand.printHand();
        
        cout << "\nThe dealers current hand is: \n";
        dealerHand.printHand();
        
        while(dealerHand.sum() < 17){
            //must continue adding cards into the dealer hand, they must have a minimum of 17
            cout << "\nSince the dealers hand is less than 17, the dealer will draw from the deck\n";
            dealAndHit(tempDeck, dealerHand);
            
            cout << "\nThis is the dealers current hand:\n";
            dealerHand.printHand();
        }
        
        if(dealerHand.sum() > 21){
            bust();
            displayWin();
        }
        
        else if(dealerHand.sum() > playerHand.sum()){
            dealerWon();
        }
        else if(dealerHand.sum() == playerHand.sum()){
            //same score result
            cout << "That's a draw.";
        }
        else{
            displayWin();
        }
    }
    else if(splitHappened){
        //indicates a split happened
        if(!splitHandBust && !playerHandBust){
            //they both did not bust.
            cout << "\nYour first hand is: ";
            playerHand.printHand();
            
            cout << "\nYour second hand is: ";
            splitHand.printHand();
            
            cout << "\nThis is the dealers current hand: ";
            dealerHand.printHand();
            
            while(dealerHand.sum() < 17){
                //must continue adding cards into the dealer hand, they must have a minimum of 17
                cout << "\nSince the dealers hand is less than 17, the dealer will draw from the deck\n";
                dealAndHit(tempDeck, dealerHand);
                
                cout << "\nThis is the dealers current hand:\n";
                dealerHand.printHand();
            }
            
            if(dealerHand.sum() > 21){
                bust();
                displayWin();
            }
            else if(playerHand.sum() > dealerHand.sum() && splitHand.sum() > dealerHand.sum()){
                cout << "\nCongratulations, you won both hands!\n";
            }
            else if(dealerHand.sum() > playerHand.sum() && dealerHand.sum() > splitHand.sum()){
                cout << "\nThe dealer has won both hands.\n";
            }
            //didnt code blackjack for splithands
            else if((dealerHand.sum() > playerHand.sum()) && !(dealerHand.sum() > splitHand.sum())){
                cout << "\nThe dealer beat this hand:" << endl;
                playerHand.printHand();
                cout << "\n however, you beat him with this hand:" << endl;
                splitHand.printHand();
            }
            else if(playerHand.sum() == dealerHand.sum()){
                //same score result
                cout << "That's a draw.";
            }
            else{
                displayWin();
            }
        }
        else if(splitHandBust && !playerHandBust){
            cout << "\nYour first hand is: \n";
            playerHand.printHand();
            
            cout << "\nThe dealers current hand is: \n";
            dealerHand.printHand();
            
            while(dealerHand.sum() < 17){
                //must continue adding cards into the dealer hand, they must have a minimum of 17
                cout << "\nSince the dealers hand is less than 17, the dealer will draw from the deck\n";
                dealAndHit(tempDeck, dealerHand);
                
                cout << "\nThis is the dealers current hand:\n";
                dealerHand.printHand();
            }
            if(dealerHand.sum() > 21){
                bust();
                displayWin();
            }
            
            else if(dealerHand.sum() > playerHand.sum()){
                dealerWon();
            }
            else if(dealerHand.sum() == playerHand.sum()){
                //same score result
                cout << "That's a draw.";
            }
            else{
                displayWin();
            }
        }
        else if(!splitHandBust && playerHandBust){
            cout << "\nYour first hand is: \n";
            splitHand.printHand();
            
            cout << "\nThe dealers current hand is: \n";
            splitHand.printHand();
            
            while(dealerHand.sum() < 17){
                //must continue adding cards into the dealer hand, they must have a minimum of 17
                cout << "\nSince the dealers hand is less than 17, the dealer will draw from the deck\n";
                dealAndHit(tempDeck, dealerHand);
                
                cout << "\nThis is the dealers current hand:\n";
                dealerHand.printHand();
            }
            if(dealerHand.sum() > 21){
                bust();
                displayWin();
            }
            else if(dealerHand.sum() > splitHand.sum()){
                dealerWon();
            }
            else if(dealerHand.sum() == splitHand.sum()){
                //same score result
                cout << "That's a draw.";
            }
            else{
                displayWin();
            }
        }
    }
}



bool blackjackFirst(Hand & playerHand, Hand & computerHand, Hand & dealerHand){
    //determines if the first deal has a blackjack or not.
    
    bool isThere = false;
    int tempCard = dealerHand.getCard(0);
    if(playerHand.hasBlackjack() && !dealerHand.hasBlackjack() && !computerHand.hasBlackjack()){
        displayWin();
        isThere = true;
    }
    else if(!playerHand.hasBlackjack() && !dealerHand.hasBlackjack() && computerHand.hasBlackjack()){
        computerWon();
        isThere = true;
    }
    else if(playerHand.hasBlackjack() && computerHand.hasBlackjack() && !dealerHand.hasBlackjack()){
        draw();
        isThere = true;
    }
    else if(tempCard >= 10 || tempCard == 1){
        //possibility for dealer has blackjack: therefore he checks to see.
        cout << "\nThe dealers now going to check for blackjack\n";
        if(dealerHand.hasBlackjack() && !playerHand.hasBlackjack() && !computerHand.hasBlackjack()){
            messagePrintHand(2, dealerHand);
            dealerWon();
            isThere = true;
            
        }
        else if(dealerHand.hasBlackjack() && playerHand.hasBlackjack() && computerHand.hasBlackjack()){
            messagePrintHand(2, dealerHand);
            draw();
            isThere = true;
        }
        else if(dealerHand.hasBlackjack() && playerHand.hasBlackjack() && !computerHand.hasBlackjack()){
            messagePrintHand(2, dealerHand);
            draw();
            isThere = true;
        }
        else if(!playerHand.hasBlackjack() && dealerHand.hasBlackjack() && computerHand.hasBlackjack()){
            messagePrintHand(2, dealerHand);
            draw();
            isThere = true;
        }
        else if(!dealerHand.hasBlackjack()){
            isThere = false;
            cout << "\nThe dealer does not have blackjack, you may continue playing\n";
        }
    }
    return isThere;
}


void playGameAI(){
    Hand playerHand;
    Hand dealerHand;
    Hand computerHand;
    Deck tempDeck;
    
    int number = 1;
    while(number < 7){
        if(number < 3){
            //deals the players first two cards
            dealAndHit(tempDeck, playerHand);
        }
        else if(number < 5){
            //deals the computers first two cards
            dealAndHit(tempDeck, computerHand);
        }
        else if(number < 7){
            //deals the dealers first two cards.
            dealAndHit(tempDeck, dealerHand);
        }
        number++;
    }
    
    //Prints the three decks.
    messagePrintHand(1, playerHand);
    messagePrintHand(3, computerHand);
    
    //displays the dealers first card:
    cout << "\nThis is the dealers hand. One card is upside down\n";
    int tempCard = dealerHand.getCard(0);
    dealerHand.displayCards(tempCard);
    cout << "\n";
    dealerHand.displayCards(0);
    
    if(blackjackFirst(playerHand, computerHand, dealerHand)){
        //determines if any of these hands have blackjack during the first draw.
        return;
    }
    
    bool computerBust = false;
    bool playerBust = false;
    
    
    //The following code has to do with the computer hitting/staying.
    cout << "\nThe AI will be going first.";
    while(probability(computerHand, dealerHand, tempDeck) >= 50 && computerHand.sum() <= 18){
        //is this really the best choice? if the computers sum is less than 17, then its highly likely to lose.
        cout << "\nThe AI has decided to hit.\n";
        dealAndHit(tempDeck, computerHand);
        messagePrintHand(3, computerHand);
    }
    if(computerHand.sum() > 21){
        bust();
        computerBust = true;
    }
    else if(computerHand.sum() < 21){
        cout << "\nThe AI has decided to stay\n";
    }
    else if(computerHand.sum() == 21){
        cout << "\nThe computer has blackjack. It's still possible for a draw.\n";
    }
    //The code for the computer hitting/staying has ended.
    
    int choice = 0;
    while(choice!=2){
        cout << "\nSelect the value for your next move: ";
        cout << "\n1. Hit";
        cout << "\n2. Stay";
        
        if(playerHand.getCard(0) == playerHand.getCard(1)){
            cout << "\nSorry, we do not allow splits in this version of the game.";
        }
        
        cout << "\nYou have a " << probability(playerHand, dealerHand, tempDeck)
        << "% of not going over 21\n";
        choice = isItValid(2);
        
        
        //player has decided to hit
        if(choice == 1){
            dealAndHit(tempDeck, playerHand);
            messagePrintHand(1, playerHand);
            
            if(playerHand.hasBlackjack()){
                choice = 2;
                if(computerHand.hasBlackjack()){
                    draw();
                    return;
                }
                else{
                    displayWin();
                    return;
                }
            }
            else if(playerHand.sum() > 21){
                choice = 2;
                playerBust = true;
                if(computerHand.hasBlackjack()){
                    cout << "\nThe computer wins this round.\n";
                    return;
                }
                else if(computerBust){
                    dealerWon();
                    return;
                }
                else{
                    choice = 2; //ensures we exit of the loop: only have to test players hand
                }
            }
        }
    }
    //player has either decided to stay, or continue hitting for player has ended.
    
    cout << "\nThese are the final hands: \n";
    messagePrintHand(1, playerHand);
    messagePrintHand(3, computerHand);
    messagePrintHand(2, dealerHand);
    
    while(dealerHand.sum() < 17){
        //ensures the dealer has at least 17 cards.
        cout << "\nSince the dealers hand is less than 17, the dealer will draw from the deck\n";
        dealAndHit(tempDeck, dealerHand);
        messagePrintHand(2, dealerHand);
    }
    
    if(dealerHand.sum() > 21){
        //dealer has busted, only between player and computer
        if(playerBust){
            //auto win for computer, since player busted
            computerWon();
            return;
        }
        else if(computerBust){
            //auto win for player since computer busted
            displayWin();
            return;
        }
        else if(playerHand.sum() > computerHand.sum()){
            //the player has a greater total, they win.
            displayWin();
            return;
        }
        else if(computerHand.sum() > playerHand.sum()){
            //computer has a greater total, they win.
            computerWon();
            return;
        }
        else{
            //there was a tie.
            draw();
            return;
        }
    }
    
    else if(dealerHand.sum() == 21){
        //this can only happen if the other players do not have blackjack
        dealerWon();
        return;
    }
    
    else if(playerBust){
        //player busted early on, only look at computer and dealer
        if(dealerHand.sum() > computerHand.sum()){
            dealerWon();
            return;
        }
        else if(computerHand.sum() > dealerHand.sum()){
            computerWon();
            return;
        }
        else{
            draw();
            return;
        }
    }
    else if(computerBust){
        //the computer busted early on: only look at player and dealer
        if(dealerHand.sum() > playerHand.sum()){
            dealerWon();
            return;
        }
        else if(playerHand.sum() > dealerHand.sum()){
            displayWin();
            return;
        }
        else{
            draw();
            return;
        }
    }
    else{
        //we must look at all three since none busted.
        if(playerHand.sum() > computerHand.sum()){
            if(playerHand.sum() > dealerHand.sum()){
                displayWin();
                return;
            }
            else if(dealerHand.sum() > playerHand.sum()){
                dealerWon();
                return;
            }
            else{
                draw();
                return;
            }
        }
        else if(playerHand.sum() < computerHand.sum()){
            if(computerHand.sum() > dealerHand.sum()){
                computerWon();
                return;
            }
            else if(dealerHand.sum() > computerHand.sum()){
                dealerWon();
                return;
            }
            else{
                draw();
            }
        }
        else if(playerHand.sum() == computerHand.sum()){
            if(playerHand.sum() > dealerHand.sum()){
                draw();
                return;
            }
            else if(dealerHand.sum() > playerHand.sum()){
                dealerWon();
            }
            else{
                draw();
                return;
            }
        }
    }
}


int main() {
    srand(time(NULL));
    displayWelcome();
    initialMenu(); //menu 1 indicates: first menu.
    int menuChoice = isItValid(2); //2 indicates number of choices
    if(menuChoice == 1){
        Instructions();
    }

    int choice = 0;
    while(choice != 3){
        secondMenu();
        choice = isItValid(3); //3 indicates the number of choices
        
        if(choice == 1){
            playGame();
        }
        if(choice == 2){
            playGameAI();
        }
    }
}

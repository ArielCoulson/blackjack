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

void initialMenu(){
    cout << "\nWelcome to Blackjack! Have fun playing!\n";
    cout << "\nWould you like to know the game instructions?\n"
    << "Enter the number value for your choice:\n"
    << "1. Yes \n"
    << "2. No \n";
}

void secondMenu(){
    cout << "\n\nEnter the number value for your choice:";
    cout <<"\n1. Start a single player game!";
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
    
    //NEEDS TO BE FORMATTEDD!!!! VVV
    cout << "\tPlease note: this version of blackjack only allows splits of the same exact card value in the first round\n";
}

void youWon(){
    cout << "\nCONGRATULATIONS! YOU WON!\n";
}

void dealerWon(){
    cout << "\nThe dealer won this time. Better luck next time.\n";
}

void bust(){
    cout << "\nThat's a bust!\n";
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

void probability(Hand & playerHand, Hand & dealerHand, Deck & tempDeck){
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
        else if(tempDeck.getCard(i) == 1){
            if((playerScore + 11) <= 21){
                count++;
            }
            else if((playerScore + 1) <= 21){
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
    cout << "\nThis is the probability that you won't go over 21: " << probability << "%\n";
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
        else if(number < 5){
            //deals the dealers two initial cards
            dealAndHit(tempDeck, dealerHand);
        }
        number++;
    }
    
    cout << "\nThe two cards the dealer has dealt you are :\n";
    playerHand.printHand();
    if(playerHand.hasBlackjack() && !(dealerHand.hasBlackjack())){
        //may be want to reveal dealers hand too to show that they dont have blackjack??
        youWon();
        return;
    }

    cout << "\nThe dealer has two cards. One is faced down, this is the other:\n";
    int tempCard = dealerHand.getCard(0);
    dealerHand.displayCards(tempCard);
    if(tempCard == 1 || tempCard >= 10){
        //dealer automatically checks for black jack w/ an ace or cards value 10.
        cout << "\nThe dealer is now checking to see if they have blackjack.\n";
        if(dealerHand.hasBlackjack()){
            dealerWon();
            return;
        }
        else{
            cout << "\n The dealer does not have blackjack. You may continue playing.\n";
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
                youWon();
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
                if(playerHand.sum() > 21){
                    bust();
                    cout << "\nNow we will work with your other split deck";
                    playerHandBust = true;
                    firstSplitDone = true;
                }
                else if(playerHand.sum() == 21){
                    youWon();
                    firstSplitDone = true;
                    playerHandBust = true;
                }
            }
            if(firstSplitDone){
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
                    youWon();
                    splitHandBust = true;
                }
            }
        }
        else if(choice == 2){
            if(splitHappened && !firstSplitDone){
                firstSplitDone = true;
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
            youWon();
        }

        else if(dealerHand.sum() > playerHand.sum()){
            dealerWon();
        }
        else if(dealerHand.sum() == playerHand.sum()){
            //same score result
            cout << "That's a draw.";
        }
        else{
            youWon();
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
                youWon();
            }
            else if(playerHand.sum() > dealerHand.sum() && splitHand.sum() > dealerHand.sum()){
                cout << "\nCongratulations, you won both hands!\n";
            }
            else if(dealerHand.sum() > playerHand.sum() && dealerHand.sum() > splitHand.sum()){
                cout << "\nThe dealer has won both hands.\n";
            }
            //didnt code blackjack for splithands
            else if(playerHand.sum() == dealerHand.sum()){
                //same score result
                cout << "That's a draw.";
            }
            else{
                youWon();
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
                youWon();
            }
            
            else if(dealerHand.sum() > playerHand.sum()){
                dealerWon();
            }
            else if(dealerHand.sum() == playerHand.sum()){
                //same score result
                cout << "That's a draw.";
            }
            else{
                youWon();
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
                youWon();
            }
            else if(dealerHand.sum() > splitHand.sum()){
                dealerWon();
            }
            else if(dealerHand.sum() == splitHand.sum()){
                //same score result
                cout << "That's a draw.";
            }
            else{
                youWon();
            }
        }
    }
}


int main() {
    srand(time(NULL));
    
    initialMenu(); //menu 1 indicates: first menu.
    int choice = isItValid(2); //2 indicates number of choices
    if(choice == 1){
        Instructions();
    }

    while(choice != 3){
        secondMenu();
        choice = isItValid(3); //3 indicates the number of choices
        
        if(choice == 1){
            playGame();
        }
    }
}

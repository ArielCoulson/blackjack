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


void Instructions ()
{
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
    cout << "\n Please note: this version of blackjack only allows splits of the same exact card value\n";
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
        
        if(menu == 1){
            //first menu only has two options!
            if(choice.length() > 1 || (choice.at(0) != '1' && choice.at(0) != '2')){
                cin.clear();
                cin.ignore();
                cout << "Not a valid option, please try again.";
                valid = false;
            }
        }
        else if(menu == 2){
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

void playGame(){
    Hand playerHand;
    Hand dealerHand;
    Hand splitHand;
    Deck tempDeck;
    
    int temp; //temp place holder for the variable at a certain location of deck
    int location; //location to pull from deck.
    int number = 1;
    while(number < 5){
        //distributes the initial 4 cards-- 2 to the dealer, 2 to the player
        if(number < 3){
            dealAndHit(tempDeck, playerHand);
        }
        else if(number < 5){
            dealAndHit(tempDeck, dealerHand);
        }
        number++;
    }
    cout << "dealer";
    dealerHand.printHand();
    
    cout << "player";
    playerHand.printHand();
    
    cout << "deck";
    tempDeck.printDeck();
    
}


int main() {
    srand(time(NULL));
    

    initialMenu(); //menu 1 indicates: first menu.
    int choice = isItValid(1);
    if(choice == 1){
        Instructions();
    }
    
    while(choice != 3){
        secondMenu();
        choice = isItValid(2); //the 2 indicates that we are checking the 2nd menu.
        
        if(choice == 1){
            playGame();
        }
    }
    
    
    
}

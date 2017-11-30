//
//  Hand.cpp
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
#include "Hand.h"

//Hand class.

Hand::Hand(){
    //nothing the vector needs to be empty once called upon.
}

void Hand::addCard(int card){
    theHand.push_back(card);
}

void Hand::removeCard(){
    //removes card from top, especially useful for splits.
    theHand.pop_back();
}

void Hand::clearHand(){
    theHand.clear();
}

void Hand::displayCards(int value){
    //Some cards are displaying oddly, need to fix!
    //code a blacked out card
    string cardDisplay = "";
    string line1 = " ";
    string line10 = " ";
    //this will be the top border of the card
    for (int i = 0; i< 15; i++) {
        line1 += "-";
        line10 += "-";
    }
    //blank line
    string line2 = "|               |";
    
    string line3 = "";
    string line4 = "";
    string line5 = "";
    string line6 = "";
    string line7 = "";
    string line8 = "";
    string line9 = "";
    string line11 = line2;
    
    
    
    if(value == 1){
        line3 = "|        .         |";
        line4 = "|       /\\        |";
        line5 = "|      /  \\       |";
        line6 = "|     /    \\      |";
        line7 = "|    / _____\\     |";
        line8 = "|   /        \\    |";
        line9 = "|  /          \\   |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    
    else if(value == 2){
        line3 = "|    ________   |";
        line4 = "|            |  |";
        line5 = "|            |  |";
        line6 = "|     _______|  |";
        line7 = "|    |          |";
        line8 = "|    |          |";
        line9 = "|    |________  |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 3){
        line3 = "|    ________   |";
        line4 = "|            |  |";
        line5 = "|            |  |";
        line6 = "|     _______|  |";
        line7 = "|            |  |";
        line8 = "|            |  |";
        line9 = "|    ________|  |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 4){
        line3 = "|               |";
        line4 = "|    |       |  |";
        line5 = "|    |       |  |";
        line6 = "|    |_______|  |";
        line7 = "|            |  |";
        line8 = "|            |  |";
        line9 = "|            |  |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 5){
        line3 = "|    _______    |";
        line4 = "|    |          |";
        line5 = "|    |          |";
        line6 = "|    |______    |";
        line7 = "|           |   |";
        line8 = "|           |   |";
        line9 = "|    _______|   |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 6){
        line3 = "|    _______    |";
        line4 = "|    |          |";
        line5 = "|    |          |";
        line6 = "|    |______    |";
        line7 = "|    |      |   |";
        line8 = "|    |      |   |";
        line9 = "|    |______|   |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 7){
        line3 = "|    _______    |";
        line4 = "|           |   |";
        line5 = "|           |   |";
        line6 = "|           |   |";
        line7 = "|           |   |";
        line8 = "|           |   |";
        line9 = "|           |   |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 8){
        line3 = "|    _______    |";
        line4 = "|    |      |   |";
        line5 = "|    |      |   |";
        line6 = "|    |______|   |";
        line7 = "|    |      |   |";
        line8 = "|    |      |   |";
        line9 = "|    |______|   |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 9){
        line3 = "|    ________   |";
        line4 = "|    |       |  |";
        line5 = "|    |       |  |";
        line6 = "|    |_______|  |";
        line7 = "|            |  |";
        line8 = "|            |  |";
        line9 = "|    ________|  |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 10){
        line3 = "|       ____    |";
        line4 = "|   |   |   |   |";
        line5 = "|   |   |   |   |";
        line6 = "|   |   |   |   |";
        line7 = "|   |   |   |   |";
        line8 = "|   |   |___|   |";
        line9 = "|               |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 11){
        line3 = "|     ______    |";
        line4 = "|        |      |";
        line5 = "|        |      |";
        line6 = "|        |      |";
        line7 = "|        |      |";
        line8 = "|    |___|      |";
        line9 = "|               |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 12){
        line3 = "|   ________    |";
        line4 = "|   |       |   |";
        line5 = "|   |       |   |";
        line6 = "|   |       |   |";
        line7 = "|   |       |   |";
        line8 = "|   |_______|   |";
        line9 = "|           \\     |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else  if(value == 13){
        line3 = "|                 |";
        line4 = "|   |       /     |";
        line5 = "|   |      /      |";
        line6 = "|   |    <        |";
        line7 = "|   |     \\      |";
        line8 = "|   |      \\     |";
        line9 = "|   |       \\    |";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    else{
        line3 = "|||||||||||||||||";
        line4 = "|||||||||||||||||";
        line5 = "|||||||||||||||||";
        line6 = "|||||||||||||||||";
        line7 = "|||||||||||||||||";
        line8 = "|||||||||||||||||";
        line9 = "|||||||||||||||||";
        
        cardDisplay = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line11 + "\n" + line10;
    }
    cout << cardDisplay;
}

void Hand:: printHand(){
    for (vector<int>::const_iterator i = theHand.begin(); i != theHand.end(); ++i){
        //prints out the players hand.
        int value = *i;
        displayCards(value);
    }
}

int Hand::sum(){
    //calculates sum of the current hand.
    int sum = 0;
    int value;
    int aceCount = 0;
    
    for(int i = 0; i < theHand.size(); i++){
        value = theHand[i];
        if(value != 1){
            if(value == 11 || value == 12 || value == 13){
                sum += 10;
            }
            else{
                sum += value;
            }
        }
        else{
            aceCount++;
        }
    }
    if(aceCount > 0){
        while(aceCount > 0){
            if((sum+11) > 21){
                sum += 1;
            }
            else{
                sum += 11;
                
            }
            aceCount--;
        }
    }
    return sum;
}

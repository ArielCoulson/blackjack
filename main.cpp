//
//  main.cpp
//  blackjack
//
//
//


//only to call SRAND ONCE, make mul
//make the game logic itself a function
//pass vectors by refernece m8
//google range based for loops
//look up enum-- try to use it in ur code
/*
 enum CardValue{
 ACE = 0
 JACK = 11
 QUEEN = 12
 KING = 13
 }
 */

#include <random>
using namespace std;
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>


int sum(vector <int> hand){
    int sum = 0;
    int value;
    int aceCount = 0;
    
    for(int i = 0; i < hand.size(); i++){
        value = hand[i];
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


vector<int> setDeck(){
    vector<int> deck;
    /*
     In the deck these following numerical values represent certain cards.
     01: A
     11: J
     12: Q
     13: K
     */
    for(int i = 1; i <= 13; i++){
        //places all of the cards into the deck
        for(int j = 0; j < 4; j++){
            deck.push_back(i);
        }
    }
    return deck;
}


int randomLocation(long size){
    int location;
    location = rand() % size-1 + 1;
    return location;
}

void displayPlayerCards(int value){
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



void printHand(vector<int> hand){
    //prints any vector passed in.
    for (vector<int>::const_iterator i = hand.begin(); i != hand.end(); ++i){
        //prints out the players hand.
        int value = *i;
        displayPlayerCards(value);
    }
}

bool isThereBlackjack(vector <int> hand){
    //checks to see if the current hand has blackjack.
    bool blackjack = false;
    if(sum(hand) == 21){
        blackjack = true;
    }
    return blackjack;
}

void menu(){
    cout << "\n\nEnter the number value for your choice:";
    cout <<"\n1. Start a single player game!";
    cout <<"\n2. Start a game alongside a computer!";
    cout <<"\n3. I would like to exit.";
    
    //have a step by step tutorial, explaining game.
    /*
     ai game is it going to have a computer play alongside the one player.
     or is it going to have the ai playing against the dealer alone.
     */
}


double probability (vector<int> playerHand, vector<int> deck, vector<int> dealerHand){
    //calculating special sum for probability
    //automatically takes Aces as ones.
    int sum = 0;
    int value = 0;
    for(int i = 0; i < playerHand.size(); i++){
        value = playerHand[i];
        if(value != 1){
            if(value == 11 || value == 12 || value == 13){
                sum += 10;
            }
            else{
                sum += value;
            }
        }
    }
    double probability = 0;
    double playerScore = sum;
    int count = 0;
    
    for (int i = 0; i < deck.size(); i++){
        if(deck[i] > 10){
            if(playerScore + 10 <= 21){
                count++;
            }
        }
        else if(deck[i] == 1){
            if((playerScore + 11) <= 21){
                count++;
            }
            else if((playerScore + 1) <= 21){
                count++;
            }
        }
        else if ((playerScore + deck[i] <= 21)) {
            count++;
        }
    }
    
    if (playerScore + dealerHand[1] <= 21) {
        count++;
    }
    probability = (count * 100) / (deck.size() + 1);
    return probability;
}


void playGame(vector <int> deck){
    vector<int> playerHand;
    vector<int> dealerHand;
    vector<int> splitPlayerHand;
    
    int temp;
    int location;
    
    int number = 1;
    while(number < 5){
        //represents the first set of cards to be delt
        if(number < 3){
            //places the cards into the players hand
            location = randomLocation(deck.size());
            temp = deck[location];
            playerHand.push_back(temp);
            deck.erase(deck.begin() + location);
        }
        else{
            //places the cards into the dealers hand
            location = randomLocation(deck.size());
            temp = deck[location];
            dealerHand.push_back(temp);
            deck.erase(deck.begin() + location);
        }
        number++;
    }
    
    
    cout << "\nThe two cards the dealer has delt you are:\n ";
    printHand(playerHand);
    
    
    if(sum(playerHand) == 21){
        cout << "\nCongratulations! You Won!\n";
        return;
    }
    
    cout << "\nThe dealer has two cards. One is faced down, this is the other:\n";
    displayPlayerCards(dealerHand.front());
    
    if(dealerHand.front() == 1 || dealerHand.front() >= 10){
        cout << "\nThe dealer will now check if they have blackjack, if so you automatically lose\n";
        if(sum(dealerHand) == 21){
            cout << "\nThe dealers hand is blackjack. You automatically lose.";
            return;
        }
        else{
            cout << "\nThe dealer does not have blackjack, you may continue playing.\n";
        }
    }
    
    int playingChoice = 0;
    bool bust = false;
    bool split = false;
    bool splitDeck1 = false;
    //indicates when the player is done hitting their first split deck
    
    while(playingChoice != 2){
        cout << "\nSelect the value for your next move:";
        cout << "\n1. Hit";
        cout << "\n2. Stay";
        
        //calls probability function.
        cout << "\nThis is the probability that you will not go over 21:  ";
        double probability2 = probability(playerHand, deck, dealerHand);
        cout << probability2 << "%\n";
        
        if(playerHand[0] == playerHand[1] && !split){
            //gives the player the option to split their hand if the first two values are same.
            cout << "\n3. Split";
        }
        
        cout << "\nI choose: ";
        cin >> playingChoice;
        
        
        
        
        if(playingChoice == 1 && !split){
            //pulls from a random location in the deck, removes card from deck, places in playerhand
            location = randomLocation(deck.size());
            temp = deck[location];
            playerHand.push_back(temp);
            deck.erase(deck.begin() + location);
            
            
            cout << "\nThis is your hand: \n";
            printHand(playerHand);
            if(sum(playerHand) > 21){
                cout << "\nSorry, that's a bust. Better luck next time.";
                bust = true;
                playingChoice = 2;
            }
            if(sum(playerHand) == 21){
                cout << "\nYou won with blackjack! Congratulations!\n";
                return;
            }
        }
        else if(playingChoice == 3 && !split){
            //THIS REALLY NEEDS TO BE TESTED PLSSSSS
            //Im not sure if you can have more than one split
            split = true;
            cout << "\nYou have decided to split your deck";
            splitPlayerHand.push_back(playerHand[1]);
            playerHand.pop_back();
            cout << "\nThis is hand number 1:\n";
            printHand(playerHand);
            cout << "\nThis is hand number 2:\n";
            printHand(splitPlayerHand);
            
        }
        
        else if(playingChoice == 1 && split){
            //REALLY NEED TO TEST THIS LOGIC!!!!! (splitting logic in general)
            if(!splitDeck1){
                location = randomLocation(deck.size());
                temp = deck[location];
                playerHand.push_back(temp);
                deck.erase(deck.begin() + location);
                
                cout << "\nThis is the hand of your first split deck: ";
                printHand(playerHand);
                if(sum(playerHand) > 21){
                    cout << "\nSorry, that's a bust. Better luck with your other split deck";
                    splitDeck1 = true;
                }
                else{
                    cout << "\nIn this first deck: \n";
                }
            }
            else{
                location = randomLocation(deck.size());
                temp = deck[location];
                splitPlayerHand.push_back(temp);
                deck.erase(deck.begin() + location);
                
                
                cout << "\n This is the hand of your second split deck: ";
                printHand(splitPlayerHand);
                if(sum(splitPlayerHand)> 21){
                    cout << "Your second deck is a bust, better luck next time";
                    playingChoice = 2;
                }
            }
        }
        else if(playingChoice == 2 && split){
            if(!splitDeck1){
                splitDeck1 = true;
                //signals you are done with the first split deck. (which is "playerhand")
            }
        }
    }
    
    
    if(bust == true){
        //continue;
    }
    else{
        cout << "\nYour final hand is: \n";
        printHand(playerHand);
        
        cout << "\nThe dealers current hand is: \n";
        printHand(dealerHand);
        
        while(sum(dealerHand) < 17){
            //must continue adding cards into the dealer hand, they must have a minimum of 17
            cout << "\nSince the dealers hand is less than 17, the dealer will draw from the deck\n";
            location = randomLocation(deck.size());
            temp = deck[location];
            dealerHand.push_back(temp);
            deck.erase(deck.begin() + location - 1);
            
            cout << "\nThis is the dealers current hand:\n";
            printHand(dealerHand);
        }
        if(sum(dealerHand) > 21){
            cout << "\n The dealer has busted. You win!\n";
        }
        else if(sum(dealerHand) > sum(playerHand)){
            //dealer had a better outcome
            cout << "\nThe dealer has won this game. Better luck next time!";
        }
        else if(sum(dealerHand) == sum(playerHand)){
            //same score result
            cout << "You neither lose nor win.";
        }
        else{
            cout << "You win! Congratulations!";
        }
    }
}


int main() {
    srand(time(NULL));
    cout << "\nWelcome to Blackjack! Have fun playing!\n";
    cout << "\nWould you like to know the game instructions?\n"
    << "Enter the number value for your choice:\n"
    << "1. Yes \n"
    << "2. No \n";
    int instructionChoice;
    cout << "I choose: ";
    cin >> instructionChoice;
    
    while(instructionChoice != 1 && instructionChoice != 2){
        cout << "\nNot a valid option, please enter your choice again. \n";
        cout << "I choose: ";
        cin >> instructionChoice;
    }
    if(instructionChoice == 1){
        Instructions();
    }
    
    
    vector<int> tempDeck = setDeck();
    vector<int> deck = tempDeck;
    
    int choice = 0;
    while(choice != 3){
        menu();
        cout << "\nI choose: ";
        cin >> choice;
        if(choice == 1){
            playGame(deck);
        }
        else if(choice == 2){
            //code that calls AI function.
        }
        else if(choice == 3){
            cout << "\nThanks for checking out our game! Exiting program now.";
        }
        else{
            cout << "\nNot a valid option, please enter 1 or 2";
        }
    }
}

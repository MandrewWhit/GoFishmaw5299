//
// Created by Andrew on 4/10/2020.
//
#include "card.h"
#include "deck.h"
#include <vector>
#include <random>
#include <ctime>

/*
 *
 *default deck constructor
 *
 *
 */
Deck::Deck() {
    myIndex = 0;
    Card::Suit cardSuit = Card::spades;
    Card myCard;
    for(int j=0; j<4;j++) {      //loop through each of the suits
        if(j==0){
            cardSuit = Card::spades;
        }else if(j==1){
            cardSuit = Card::hearts;
        }else if(j==2){
            cardSuit = Card::diamonds;
        }else if(j==3){
            cardSuit = Card::clubs;
        }
        for (int i = 1; i <= 13; i++) {   //add each of the ranks 1-13
            myCard = Card(i, cardSuit);
            myCards[myIndex] = myCard;
            myIndex++;
        }
    }
    myIndex--;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

/*
 *
 *shuffle the deck
 *
 *preconditions: a deck with standard cards
 *
 *postconditions: a shuffled deck
 *
 */
void Deck::shuffle() {
    int index1;
    int range = size();
    for(int j=0;j<3;j++) {
        for (int i = 0; i < range-1; i++) {
            index1 = (rand() % 51);
            Card tempCard = myCards[i];
            myCards[i] = myCards[index1];
            myCards[index1] = tempCard;
        }
    }
}



/*
 *
 *deal a single card and update index
 *
 *preconditions: a valid deck of cards that isn't empty
 *
 *postconditions: return top card of the deck
 *
 */

Card Deck::dealCard() {
    Card dealtCard = myCards[myIndex];
    myIndex--;
    return dealtCard;
}
/*
 *find the current size of the deck
 *preconditions: a valid deck of cards
 *postconditions: return the number of cards in the deck
 */
int Deck::size() const {
    return(myIndex+1);
}












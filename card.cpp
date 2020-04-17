//
// Created by Andrew on 4/10/2020.
//

#include "card.h"
#include <string>

/*
 * Default constructor
 */
Card::Card(){
    myRank = 1;
    mySuit = spades;
}
//Non-default constructor
Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}
/*
 * return the rank and suit of a card in string format
 *
 */
string Card::toString() const {
    string number;
    number = rankString(myRank);
    string suit;
    suit = suitString(mySuit);
    string result = number + suit;
    return result;
    
}
/*
 *get the rank of a card
 */
int Card::getRank() const {
    return myRank;
}
/*
 *get the suit of a card
 */
Card::Suit Card::getSuit() const {
    return mySuit;
}
/*
 * convert the suit of a card to string
 */
string Card::suitString(Suit s) const {
    string suit;
    switch (mySuit){
        case spades:
            suit = 's';
            break;
        case hearts:
            suit = 'h';
            break;
        case diamonds:
            suit = 'd';
            break;
        case clubs:
            suit = 'c';
            break;
    }
    return suit;
}

/*
 * convert the rank of a card to string
 */
string Card::rankString(int r) const {
    string rank;
    switch (r){
        case 1:
            rank = 'A';
            break;
        case 2:
            rank = '2';
            break;
        case 3:
            rank = '3';
            break;
        case 4:
            rank = '4';
            break;
        case 5:
            rank = '5';
            break;
        case 6:
            rank = '6';
            break;
        case 7:
            rank = '7';
            break;
        case 8:
            rank = '8';
            break;
        case 9:
            rank = '9';
            break;
        case 10:
            rank = "10";
            break;
        case 11:
            rank = 'J';
            break;
        case 12:
            rank = 'Q';
            break;
        case 13:
            rank = 'K';
            break;
    }
    return rank;
}

/*
 *compare the suits of two cards
 */
bool Card::sameSuitAs(const Card &c) const {
    return(mySuit==c.mySuit);
}
/*
 *overload == and != operators
 */
bool Card::operator==(const Card &rhs) const {
    return(myRank == rhs.myRank);
}

bool Card::operator!=(const Card &rhs) const {
    return(myRank != rhs.myRank);
}


















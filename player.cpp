//
// Created by Andrew on 4/10/2020.
//

#include "player.h"

/*
 *default constructor
 */
Player::Player(){
    myName = "";
}
/*
 *add card
 *
 *preconditions: a valid card and player
 *postconditions: updated hand
 *
 */
void Player::addCard(Card c) {
    myHand.push_back(c);
}
/*
 *book cards into a players book
 *preconditions: valid cards, book and player
 *postconditions: updated book and hand
 */
void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);// add cards to players book
    myBook.push_back(c2);

    //erase c1 from hand
    int index = 0;
    while((c1.getRank()!=myHand[index].getRank())||((c1.getSuit())==(myHand[index]).getSuit())){
        index++;
    }
    Card resultCard = myHand[index];
    myHand.erase(myHand.begin() + index);

    //erase c2 from hand
    index = 0;
    while((c2.getRank()!=myHand[index].getRank())||((c2.getSuit())==(myHand[index]).getSuit())){
        index++;
    }
    resultCard = myHand[index];
    myHand.erase(myHand.begin() + index);
}
/*
 *check a players hand for a match
 *preconditions: a valid player, book, and hand
 *postconditions: return a true or false value indicating a match
 */
bool Player::checkHandForBook(Card &c1, Card &c2) {
    auto itr1 = myHand.begin();
    auto itr2 = myHand.begin();
    bool match = false;
    Card firstMatch(0, Card::spades);
    Card secondMatch(14, Card::spades);
    while(itr1!=myHand.end()){
        itr2 = myHand.begin();
        while(itr2!=myHand.end()){
            if((*itr1).getRank()==(*itr2).getRank()){
                if((*itr1).getSuit()!=(*itr2).getSuit()) {
                    firstMatch = *itr1;
                    secondMatch = *itr2;
                    match = true;
                }
            }
            itr2++;
        }
        itr1++;
    }
    if(match){
        c1 = firstMatch;
        c2 = secondMatch;
        return true;
    }else{
        return false;
    }
}

/*
 * choose the top card from the players hand
 * preconditions: a valid hand of cards
 * postconditions: return a valid card from the hand
 */

Card Player::chooseCardFromHand() const {
    return myHand[0];
}
/*
 *check to see if a player has the card in their hand
 *preconditions: a valid hand of cards
 *postconditions: return a true or false value indicated whether they have the card
 */
bool Player::cardInHand(Card c) const {
    bool haveCard = false;
    for(auto itr = myHand.begin(); itr != myHand.end(); itr++){
        if((*itr).getRank()==c.getRank()){
            haveCard = true;
        }
    }
    return haveCard;
}
/*
 *remove a card from a players hand
 *preconditions: a valid card and hand
 *postconditions: updated hand wihtout inputed card
 */
Card Player::removeCardFromHand(Card c) {

    Card resultCard;
    int index = 0;
    while(c.getRank()!=myHand[index].getRank()){
        index++;
    }
    resultCard = myHand[index];
    myHand.erase(myHand.begin() + index);
    return resultCard;
}
/*
 *show the hand of a player
 *
 *preconditions: valid hand and player
 *postconditions: return string value of hand
 */
string Player::showHand() const {
    string result;
    for(auto itr = myHand.begin(); itr != myHand.end(); itr++){
        result = result + " ";
        result = result + (*itr).toString();
    }
    return result;
}
/*
 *show the books that a player has
 *
 * preconditions: valid book and player
 *postconditions: return a string indicating booked cards
 *
 */
string Player::showBooks() const {
    string result;
    for(auto itr = myBook.begin(); itr != myBook.end(); itr++){
        result = result + " ";
        result = result + (*itr).toString();
    }
    return result;
}

/*
 *get the hand size of a player
 *preconditions: valid player and hand
 *postconditions: return an integer that indicates number of cards in hand
 */
int Player::getHandSize() const {
    int count = 0;
    for(auto itr = myHand.begin(); itr != myHand.end(); itr++){
        count++;
    }
    return count;
}
/*
 *get the number of cards that have been booked
 *must divide number by 2 to get the number of matches
 *preconditions: valid book and hand
 *postconditions: return an integer indicating number of cards in book
 */
int Player::getBookSize() const {
    int count = 0;
    for(auto itr = myBook.begin(); itr != myBook.end(); itr++){
        count++;
    }
    return count;
}













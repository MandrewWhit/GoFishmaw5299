#include <iostream>
#include "deck.h"
#include <vector>
#include "card.h"
#include "player.h"
#include <fstream>
using namespace std;

void dealHand(Deck &d, Player &p, int numCards);


int main() {

    ofstream oFile; //open the result text file
    oFile.open("gofish_results.txt");

    Card drewCard;

    int numCards = 7;  //set the number of cards dealt to start game

    Player p1("Gon");
    Player p2("Killua");

    Deck d;  //create a deck of cards
    d.shuffle();//shuffle the deck

    dealHand(d, p1, numCards);//deal a hand to players 1 and 2
    dealHand(d, p2, numCards);

    oFile << p1.getName() <<" has : " << p1.showHand() << endl;
    oFile << p2.getName() <<" has : " << p2.showHand() << endl;

    while((p1.getBookSize()+p2.getBookSize())!=52){
        //book cards that are already matches
        Card c1, c2;
        while(p1.checkHandForBook(c1, c2)){
            p1.bookCards(c1, c2);
        }
        while(p2.checkHandForBook(c1, c2)){
            p2.bookCards(c1, c2);
        }
        if((p1.getBookSize()+p2.getBookSize())!=52) {
            //p1 turn
            Card neededCard = p1.chooseCardFromHand();
            Card takenCard;
            oFile << p1.getName() << ": do you have a " << neededCard.toString() << "?" << endl;
            if (p2.cardInHand(neededCard)) {
                oFile << p2.getName() << ": Yes. I have a " << neededCard.toString() << endl;
                takenCard = p2.removeCardFromHand(neededCard);
                p1.addCard(takenCard);
            } else {
                oFile << p2.getName() << ": Sorry. I do not have a " << neededCard.toString() << ", Go Fish!" << endl;
                if (d.size() != 0) {
                    takenCard = d.dealCard();
                    oFile << p1.getName() << " drew a " << takenCard.rankString(takenCard.getRank()) << endl;
                    p1.addCard(takenCard);
                }
            }
            if(p1.checkHandForBook(c1, c2)){
                p1.bookCards(c1, c2);
            }
            if(p1.getHandSize()!=0) {
                oFile << p1.getName() << " has : " << p1.showHand() << endl;
            }else{
                oFile << p1.getName() << " has no cards left" << endl;
            }
            if(p2.getHandSize()!=0) {
                oFile << p2.getName() << " has : " << p2.showHand() << endl;
            }else{
                oFile << p2.getName() << " has no cards left" << endl;
            }
            //p2 turn
            neededCard = p2.chooseCardFromHand();
            oFile << p2.getName() << ": do you have a " << neededCard.toString() << "?" << endl;
            if (p1.cardInHand(neededCard)) {
                oFile << p1.getName() << ": Yes. I have a " << neededCard.toString() << endl;
                takenCard = p1.removeCardFromHand(neededCard);
                p2.addCard(takenCard);
            } else {
                oFile << p1.getName() << ": Sorry. I do not have a " << neededCard.toString() << ", Go Fish!" << endl;
                if (d.size() != 0) {
                    takenCard = d.dealCard();
                    oFile << p2.getName() << " drew a " << takenCard.rankString(takenCard.getRank()) << endl;
                    p2.addCard(takenCard);
                }
            }//check each player for matches to book
            while(p2.checkHandForBook(c1, c2)){
                p2.bookCards(c1, c2);
            }
            if(p1.getHandSize()!=0) {
                oFile << p1.getName() << " has : " << p1.showHand() << endl;
            }else{
                oFile << p1.getName() << " has no cards left" << endl;
                if(d.size()!=0){
                   drewCard = d.dealCard();
                   p1.addCard(drewCard);
                   oFile << p1.getName() << " drew " << drewCard.toString() << endl;
                }
            }
            if(p2.getHandSize()!=0) {
                oFile << p2.getName() << " has : " << p2.showHand() << endl;
            }else{
                oFile << p2.getName() << " has no cards left" << endl;
                if(d.size()!=0){
                   drewCard = d.dealCard();
                   p2.addCard(drewCard);
                   oFile << p2.getName() << " drew " << drewCard.toString() << endl;
                }
            }
            oFile << p1.getName() << " has " << p1.getBookSize()/2 << " book(s)" << endl;
            oFile << p2.getName() << " has " << p2.getBookSize()/2 << " book(s)" << endl;
            
        }


    }

//display winner of game
    if(p1.getBookSize()>p2.getBookSize()){
        oFile << p1.getName() << " WINS!" << endl;
    }else if(p2.getBookSize()>p1.getBookSize()){
        oFile << p2.getName() << " WINS!" << endl;
    }else{
        oFile << "TIE GAME!" << endl;
    }

    oFile.close();



}
/*
 * deal a hand to a player
 * preconditions: a valid, deck, player, and number of cards
 * postconditions: return 7 cards from the deck
 */
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



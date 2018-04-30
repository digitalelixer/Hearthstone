#include "board.h"

using namespace std;

Board::Board(void){
	this.hp = 2000;
}

void addToDeckList(Card* card){
	this.deck.push_back(card);
	return;
}


/*FIXME*/
void draw(int numCards){
	if(!(this.deck.empty()) && (numCards > 0) && (numCards <= this.deck.size())){

		while(this.deck.size() > numCards){

			Card* temp = this.field.back();
			this.hand.push_back(temp);
			this.deck.pop_back();

		}

	}

	return;
}

void playCardFromHand(int cNum);

Card* getCardOnField(int cNum);

Card* getCardInHand(int cNum);

int getHP(void){
	return this.hp;
}

void setHP(int hVal){
	this.hp = (hVal < 0)? 0 : hVal;
	return;
}

int getHandSize(void){
	return this.hand.size();
}

int getFieldSize(void){
	return this.field.size();
}

int getMana(void){
	return this.mana;
}

void setMana(int mVal){
	this.mana = (mval < 0)? 0 : mVal;
	return;
}

void discardCardFromField(int cNum){
	if(!(this.field.empty()) && (cNum > 0) && (cNum <= this.field.size())){
		Card* temp = this.field.at(cNum);
		this.discard.push_back(temp);
		this.field.erase(cNum);
	}
	return;
}

void Board::shuffleDeck(void){
    Card * temp;
    int numOfShuffles = 100;
    int idx1, idx2;
    for(int i = 0; i < numOfShuffles; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        temp = deck[idx1];
        deck[idx1] = deck[idx2];
        deck[idx2] = temp;
    }
}


void Board::renderMana(void){
    cout << "MANA: ";
    for(int i = 1; i <= maxMana; i++){
        if(i <= mana)
            cout << "@ ";
        else
            cout << "O ";
    }
        
    cout << endl;
}

void Board::renderHand(void){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::renderField(void){
    if(field.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < field.size(); j++){
                cout << field[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

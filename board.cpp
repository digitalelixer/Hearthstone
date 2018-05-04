#include "board.h"

using namespace std;

Board::Board(void){
	hp = 2000;
}

void Board::addToDeckList(Card* card){
	deck.push_back(card);
	return;
}


/*FIXME*/
void Board::draw(int numCards){

	if(!(deck.empty()) && (numCards > 0) && (numCards <= deck.size())){

		while(deck.size() > numCards){

			Card* temp = field.back();
			hand.push_back(temp);
			deck.pop_back();

		}

	}

	return;
}

void Board::playCardFromHand(int cNum){

	if(!(field.empty()) && (cNum > 0) && (cNum <= field.size())){

		setMana(getMana() - hand.at(cNum)->getManaCost());

	}

	return;
}

Card* Board::getCardOnField(int cNum){

	if(!(field.empty()) && (cNum > 0) && (cNum <= field.size())){

		return field.at(cNum);

	} else {

		return nullptr;

	}
}

Card* Board::getCardInHand(int cNum){

	if(!(hand.empty()) && (cNum > 0) && (cNum <= hand.size())){

		return hand.at(cNum);

	} else {

		return nullptr;

	}
}

int Board::getHP(void){
	return hp;
}

void Board::setHP(int hVal){
	hp = (hVal < 0)? 0 : hVal;
	return;
}

int Board::getHandSize(void){
	return hand.size();
}

int Board::getFieldSize(void){
	return field.size();
}

int Board::getMana(void){
	return mana;
}

void Board::setMana(int mVal){
	mana = (mVal < 0)? 0 : mVal;
	return;
}

void Board::discardCardFromField(int cNum){
	if(!(field.empty()) && (cNum > 0) && (cNum <= field.size())){
		Card* temp = field.at(cNum);
		discard.push_back(temp);
		field.erase(field.begin() + (cNum - 1));
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

#include "card.h"

Card::Card(string cardName, int mCost, int atk, int def){
	name = cardName;
	manaCost = (mCost < 1)? 1 : mCost;
	attack = (atk < 1)? 1 : atk;
	defense = (def < 1)? 1 : def;
	exhausted = true;
}

string Card::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

string Card::getName(void){
	return name;
}
int Card::getManaCost(void){
	return manaCost;
}
int Card::getAttack(void){
	return attack;
}
int Card::getDefense(void){
	return defense;
}
bool Card::isExhausted(void){
	return exhausted;
}

void Card::setExhausted(){
	exhausted = true;
	return;
}
void Card::unExhaust(void){
	exhausted = false;
	return;
}

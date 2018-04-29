#include "card.h"

using namespace std;

Card::Card(string cardName, int mCost, int atk, int def){
	this.name = cardName;
	this.manaCost = (mCost < 1)? 1 : mCost;
	this.attack = (atk < 1)? 1 : atk;
	this.defense = (def < 1)? 1 : def;
	this.exhausted = true;
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

string getName(void){
	return this.name;
}
int getManaCost(void){
	return this.manaCost;
}
int getAttack(void){
	return this.attack;
}
int getDefense(void){
	return this.defense;
}
bool isExhausted(void){
	return this.exhausted;
}
void unExhaust(void){
	this.exhausted = false;
	return;
}

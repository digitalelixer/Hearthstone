#include "wraith.h"

const string NAME = "Wraith";
const int MANACOST = 3;
const int ATTACK = 300;
const int DEFENSE = 300;

Goblin::Goblin(void) : Card(NAME, MANACOST, ATTACK, DEFENSE){ }

string Wraith::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Wraith     |";
        case 2: return "|   _---_   |";
        case 3: return "|  | 0 0 |  |";
        case 4: return "|  |  o  |  |";
        case 5: return "|  |_____|  |";
        case 6: return "|  300/300  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

#include "direRabbit.h"

const string NAME = "Dire Rabbit";
const int MANACOST = 2;
const int ATTACK = 200;
const int DEFENSE = 300;

DireRabbit::DireRabbit(void) : Card(NAME, MANACOST, ATTACK, DEFENSE){ }

string DireRabbit::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Dire Rabbit|";
        case 2: return "|  (||)     |";
        case 3: return "|  (..)     |";
        case 4: return "|  c_(')(') |";
        case 5: return "|           |";
        case 6: return "|  200/300  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

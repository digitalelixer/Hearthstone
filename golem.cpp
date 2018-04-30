#include "golem.h"

const string NAME = "Golem";
const int MANACOST = 3;
const int ATTACK = 100;
const int DEFENSE = 400;

Golem::Golem(void) : Card(NAME, MANACOST, ATTACK, DEFENSE){ }

string Golem::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Golem      |";
        case 2: return "|   _____   |";
        case 3: return "|  |[] []|  |";
        case 4: return "|  |     |  |";
        case 5: return "|  |_===_|  |";
        case 6: return "|  100/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

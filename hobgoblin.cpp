#include "hobgoblin.h"

const string NAME = "Hobgoblin";
const int MANACOST = 2;
const int ATTACK = 300;
const int DEFENSE = 200;

Hobgoblin::Hobgoblin(void) : Card(NAME, MANACOST, ATTACK, DEFENSE){ }

string Hobgoblin::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Hobgoblin  |";
        case 2: return "|   ^___^   |";
        case 3: return "|  ( . . )  |";
        case 4: return "|   | v |   |";
        case 5: return "|    '''    |";
        case 6: return "|  300/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

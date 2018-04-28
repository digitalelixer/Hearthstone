#include "hobgoblin.h"


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

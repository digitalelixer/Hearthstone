#include "goblin.h"


string Goblin::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Goblin     |";
        case 2: return "|   ^___^   |";
        case 3: return "|  ( . . )  |";
        case 4: return "|     v     |";
        case 5: return "|           |";
        case 6: return "|  200/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

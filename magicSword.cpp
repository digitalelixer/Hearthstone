#include "magicSword.h"


string MagicSword::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Magic Sword|";
        case 2: return "|           |";
        case 3: return "| 0=|=====> |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|  500/300  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

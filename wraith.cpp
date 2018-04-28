#include "wraith.h"


string Wraith::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Wraith     |";
        case 2: return "|   _---_   |";
        case 3: return "|  | 0 0 |  |";
        case 4: return "|  |  o  |  |";
        case 5: return "|  |_____|  |";
        case 6: return "|  500/500  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

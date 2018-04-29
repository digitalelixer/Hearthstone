#include "evilEye.h"


string EvilEye::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Evil Eye   |";
        case 2: return "|   _____   |";
        case 3: return "|  |_____|  |";
        case 4: return "|  | [_] |  |";
        case 5: return "|  |_____|  |";
        case 6: return "|  400/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

#include "dragon.h"


string Dragon::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Dragon     |";
        case 2: return "|  ^-----^  |";
        case 3: return "| (  O O  ) |";
        case 4: return "|  | . . |  |";
        case 5: return "|   vvvvv   |";
        case 6: return "|  500/500  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

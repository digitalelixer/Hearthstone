#include "wizard.h"


string Wizard::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Wizard     |";
        case 2: return "|  |=====|  |";
        case 3: return "| --------- |";
        case 4: return "|  | 0 0 |  |";
        case 5: return "|   |_-_|   |";
        case 6: return "|  500/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

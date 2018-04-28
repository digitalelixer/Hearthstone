#include "direRabbit.h"


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

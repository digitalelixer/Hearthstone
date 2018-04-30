#include "wargWolf.h"

const string NAME = "Warg Wolf";
const int MANACOST = 1;
const int ATTACK = 100;
const int DEFENSE = 100;

WargWolf::WargWolf(void) : Card(NAME, MANACOST, ATTACK, DEFENSE){ }

string WargWolf::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Warg Wolf  |";
        case 2: return "|  |)___(|  |";
        case 3: return "|  | o o |  |";
        case 4: return "|  |_   _|  |";
        case 5: return "|    |_|    |";
        case 6: return "|  100/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

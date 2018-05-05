#include "wizard.h"

const string NAME = "Wizard";
const int MANACOST = 4;
const int ATTACK = 550;
const int DEFENSE = 100;

Wizard::Wizard(void) : Card(NAME, MANACOST, ATTACK, DEFENSE){ }

string Wizard::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Wizard     |";
        case 2: return "|  |=====|  |";
        case 3: return "| --------- |";
        case 4: return "|  | 0 0 |  |";
        case 5: return "|   |_-_|   |";
        case 6: return "|  550/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

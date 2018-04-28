#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "card.h"

using namespace std;

class Wizard : public Card {
    private:
    
    public:
    
    Wizard(void);
    virtual string render(int);
};

#endif

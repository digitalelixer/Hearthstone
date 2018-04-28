#ifndef WARGWOLF_H
#define WARGWOLF_H

#include <iostream>
#include "card.h"

using namespace std;

class WargWolf : public Card {
    private:
    
    public:
    
    WargWolf(void);
    virtual string render(int);
};

#endif

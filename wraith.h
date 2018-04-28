#ifndef WRAITH_H
#define WRAITH_H

#include <iostream>
#include "card.h"

using namespace std;

class Wraith : public Card {
    private:
    
    public:
    
    Wraith(void);
    virtual string render(int);
};

#endif

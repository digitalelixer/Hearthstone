#ifndef DRAGON_H
#define DRAGON_H

#include <iostream>
#include "card.h"

using namespace std;

class Dragon : public Card {
    private:
    
    public:
    
    Dragon(void);
    virtual string render(int);
};

#endif

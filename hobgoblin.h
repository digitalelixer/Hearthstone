#ifndef HOBGOBLIN_H
#define HOBGOBLIN_H

#include <iostream>
#include "card.h"

using namespace std;

class Hobgoblin : public Card {
    private:
    
    public:
    
    hobgoblin(void);
    virtual string render(int);
};

#endif

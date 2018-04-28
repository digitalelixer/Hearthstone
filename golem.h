#ifndef GOLEM_H
#define GOLEM_H

#include <iostream>
#include "card.h"

using namespace std;

class Golem : public Card {
    private:
    
    public:
    
    Golem(void);
    virtual string render(int);
};

#endif

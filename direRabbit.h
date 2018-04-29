#ifndef DIRERABBIT_H
#define DIRERABBIT_H

#include <iostream>
#include "card.h"

using namespace std;

class DireRabbit : public Card {
    private:
    
    public:
    
    DireRabbit(void);
    virtual string render(int);
};

#endif

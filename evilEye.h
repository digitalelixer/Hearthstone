#ifndef EVILEYE_H
#define EVILEYE_H

#include <iostream>
#include "card.h"

using namespace std;

class EvilEye : public Card {
    private:
    
    public:
    
    EvilEye(void);
    virtual string render(int);
};

#endif

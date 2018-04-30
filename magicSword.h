#ifndef MAGICSWORD_H
#define MAGICSWORD_H

#include "card.h"

using namespace std;

class MagicSword : public Card {
    private:
    
    public:
    
    MagicSword(void);
    virtual string render(int);
};

#endif

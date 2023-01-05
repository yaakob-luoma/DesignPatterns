#ifndef CONCRETEFLYWEIGHT_H
#define CONCRETEFLYWEIGHT_H

#include "Flyweight.h"

class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight();

    virtual void action();

private:

};

#endif // CONCRETEFLYWEIGHT_H

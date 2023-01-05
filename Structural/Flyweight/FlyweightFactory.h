#ifndef FLYWEIGHTFACTORY_H
#define FLYWEIGHTFACTORY_H

#include <vector>

#include "Flyweight.h"

class FlyweightFactory
{
public:
    FlyweightFactory();
    virtual ~FlyweightFactory();

private:
    std::vector< Flyweight* > flyweights; // use FlyweightContext
};

#endif // FLYWEIGHTFACTORY_H

#ifndef CONCRETECOMPONENT_H
#define CONCRETECOMPONENT_H

#include "Component.h"

class ConcreteComponent : public Component
{
public:
    ConcreteComponent();
    ~ConcreteComponent();

    virtual void operation();
};

#endif // CONCRETECOMPONENT_H

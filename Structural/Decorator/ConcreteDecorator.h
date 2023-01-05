#ifndef CONCRETEDECORATOR_H
#define CONCRETEDECORATOR_H

#include "Decorator.h"

class ConcreteDecorator : public Decorator
{
public:
    ConcreteDecorator(Component*, int);
    ~ConcreteDecorator();

    virtual void operation();

private:
    void operationSpecific(int);
    int specific;
};

#endif // CONCRETEDECORATOR_H

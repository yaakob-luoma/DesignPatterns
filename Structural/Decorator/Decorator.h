#ifndef DECORATOR_H
#define DECORATOR_H

#include "Component.h"

class Decorator : public Component
{
public:
    Decorator(Component*);
    ~Decorator();

    virtual void operation();

private:
    Component* comp;
};

#endif // DECORATOR_H

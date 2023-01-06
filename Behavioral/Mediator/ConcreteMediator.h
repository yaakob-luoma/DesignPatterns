#ifndef CONCRETE_MEDIATOR_H
#define CONCRETE_MEDIATOR_H

#include "AbstractMediator.h"
#include "Component1.h"
#include "Component2.h"

class ConcreteMediator : public Mediator
{
private:
    Component1 *component1_ptr;
    Component2 *component2_ptr;

public:
    ConcreteMediator( Component1 *c1
                      , Component2 *c2 );

    void notify( BaseComponent *sender
                 , std::string event ) const override;

};


#endif

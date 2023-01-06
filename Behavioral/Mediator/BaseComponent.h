#ifndef BASE_COMPONENT_H
#define BASE_COMPONENT_H

#include "AbstractMediator.h"

class BaseComponent
{
protected:
    Mediator *mediator_ptr;
public:
    BaseComponent( Mediator *mediator = nullptr );

    void setMediator( Mediator *mediator );
};

#endif

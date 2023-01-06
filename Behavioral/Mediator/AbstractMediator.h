#ifndef ABSTRACT_MEDIATOR_H
#define ABSTRACT_MEDIATOR_H

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

#include "BaseComponent.h"

class Mediator
{
public:
    virtual void notify( BaseComponent *sender, std::string event ) const = 0;
};

#endif

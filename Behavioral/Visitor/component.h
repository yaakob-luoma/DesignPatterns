#include "vistor.h"

class Component
{
public:
    virtual ~Component(){};
    virtual void accept( Visitor *vistor ) const = 0;
};

#include <string>

#include "component.h"
#include "visitor.h"

class ConcreteComponentB : public Component
{
public:
    void accept( Visitor *vistor ) const override
    {
        vistor->visitConcreteComponentB( this );
    }
    std::string exclusiveMethodOfConcreteComponenetB() const
    {
        return "B";
    }
};

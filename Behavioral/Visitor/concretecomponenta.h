#include <string>


#include "component.h"
#include "visitor.h"

class ConcreteComponentA : public Component
{
public:
    void accept( Visitor *vistor ) const override
    {
        vistor->visitConcreteComponentA( this );
    }
    std::string exclusiveMethodOfConcreteComponenetA() const
    {
        return "A";
    }
};

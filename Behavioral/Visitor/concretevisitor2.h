#include "concretecomponenta.h"
#include "concretecomponentb.h"
#include "visitor.h"

class ConcreteVisitor2 : public Visitor
{
public:
    void visitConcreteComponentA( const ConcreteComponentA *element ) const override
    {
        std::cout << element->exclusiveMethodOfConcreteComponenetA()
                  << " + ConcreteVisitor2\n";
    }
    void visitConreteComponentB( const ConcreteComponentB *element ) const override
    {
        std::cout << element->exclusiveMethodOfConcreteComponenetB()
                  << " + ConcreteVisitor2\n";
    }
};
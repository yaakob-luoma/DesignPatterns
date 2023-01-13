#include "concretecomponenta.h"
#include "concretecomponentb.h"
#include "visitor.h"

class ConcreteVisitor1 : public Visitor
{
public:
    void visitConcreteComponentA( const ConcreteComponentA *element ) const override
    {
        std::cout << element->exclusiveMethodOfConcreteComponenetA()
                  << " + ConcreteVisitor1\n";
    }
    void visitConreteComponentB( const ConcreteComponentB *element ) const override
    {
        std::cout << element->exclusiveMethodOfConcreteComponenetB()
                  << " + ConcreteVisitor1\n";
    }
};

#include "concretecomponenta.h"
#include "concretecomponentb.h"

class Visitor
{
public:
    virtual void visitConcreteComponentA( const ConcreteComponentA *element ) const = 0;
    virtual void visitConcreteComponentB( const ConcreteComponentB *element ) const = 0;
};
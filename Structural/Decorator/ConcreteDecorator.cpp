#include "ConcreteDecorator.h"

ConcreteDecorator::ConcreteDecorator(Component* c, int s)
{
    comp = c ;
    specific = s;
}

ConcreteDecorator::~ConcreteDecorator()
{

}

void ConcreteDecorator::operation()
{
    Decorator::operation();
    operationSpecific( specific );
}


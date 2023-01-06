#include "Component2.h"

void Component2::doC()
{
    std::cout << "Component 2 does C.\n";
    mediator_ptr->notify(this, "C");
}
void Component2::doD()
{
    std::cout << "Component 2 does D.\n";
    mediator_ptr->notify( this, "D");
}

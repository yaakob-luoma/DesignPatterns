#include "Component1.h"


void Component1::doA()
{
    std::cout << "Component 1 does A.\n";
    mediator_ptr->notify(this, "A");
}
void Component1::doB()
{
    std::cout << "Component 1 does B.\n";
    mediator_ptr->notify(this, "B");
}

#include "Component1.h"
#include "Component2.h"
#include "ConcreteMediator.h"

void clientCode()
{
    Component1 *c1 = new Component1;
    Component2 *c2 = new Component2;
    ConcreteMediator *mediator = new ConcreteMediator( c1, c2);
    std::cout << "Client tiggers operation A.\n";
    c1->doA();
    std::cout << "\n";
    std::cout << "Client triggers operation B.\n";
    c2->doD();

    delete c1;
    delete c2;
    delete mediator;
}

int main()
{
    clientCode();
    return 0;
}

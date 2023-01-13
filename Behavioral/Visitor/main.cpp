#include <string>
#include <iostream>
#include <array>

void clientCode( std::array<const Component*, 2> components, Visitor *Visitor )
{
    for ( const Component *component : components )
    {
        component.accept( visitor );
    }
}

int main()
{
    std::array< const Component *, 2> components = {new ConcreteComponentA, new ConcreteComponentB};
    std::cout << "The client code works with all visitors via the base Visitor interface:\n";
    ConcreteVisitor1 *visitor1 = new ConcreteVisitor1();
    clientCode( components, visitor1 );
    std::cout << "\n";
    std::cout << "It allows the same client code to work with different types of visitors:\n";
    ConcreteVisitor2 *visitor2 = new ConcreteVisitor2();
    clientCode( components, visitor2 );

    for( const Component *component : components )
    {
        delete component;
    }
    delete visitor1;
    delete visitor2;

    return 0;
}

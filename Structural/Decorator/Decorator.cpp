
#include <string>
#include <iostream>

class Component
{
public:
    virtual ~Component(){}
    virtual std::string operation() const = 0;
};

class ConcreteComponent : public Component
{
public:
    std::string operation() const override
    {
        return "ConcreteComponent";
    }
};

class Decorator : public Component
{
protected:
    Component *component_ptr;
public:
    Decorator( Component *component ) : component_ptr( component ) {}
    std::string operation() const override
    {
        return component_ptr->operation();
    }
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA( Component *component ) : Decorator(component) {}
    std::string operation() const override
    {
        return "ConcreteDecoratorA(" + Decorator::operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB( Component *component ) : Decorator( component ){}
    std::string operation() const override
    {
        return "ConcreteDecoratorB(" + Decorator::operation() + ")";
    }
};

void clientCode( Component *component )
{
    std::cout << "RESULT: " << component->operation();
}

int main()
{
    Component *simple = new ConcreteComponent();
    std::cout << "Client: I've got a simple component:\n";
    clientCode( simple );
    std::cout << "\n\n";

    Component *decorator1 = new ConcreteDecoratorA(simple);
    Component *decorator2 = new ConcreteDecoratorB( decorator1 );
    std::cout << "Client: Now I've got a decorated component:\n";
    clientCode( decorator2 );
    std::cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Client: I've got a simple component:
 * RESULT: ConcreteComponent
 *
 * Client: Now I've got a decorated component:
 * RESULT: ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))
 */

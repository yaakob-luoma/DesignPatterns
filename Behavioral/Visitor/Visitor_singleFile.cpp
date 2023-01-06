
#include <string>
#include <iostream>
#include <array>

class ConcreteComponentA;
class ConcreteComponentB;

class Visitor
{
public:
    virtual void visitConcreteComponentA( const ConcreteComponentA *element ) const = 0;
    virtual void visitConcreteComponentB( const ConcreteComponentB *element ) const = 0;
};

class Component
{
public:
    virtual ~Component(){};
    virtual void accept( Visitor *vistor ) const = 0;
};

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

class ConcreteComponentB : public Component
{
public:
    void accept( Visitor *vistor ) const override
    {
        vistor->visitConcreteComponentB( this );
    }
    std::string exclusiveMethodOfConcreteComponenetB() const
    {
        return "B";
    }
};

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

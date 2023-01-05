
#include <string>
#include <iostream>

class Implementation
{
public:
    virtual ~Implementation(){}
    virtual std::string operationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation
{
public:
    std::string operationImplementation() const override
    {
        return "ConcreteImplementationA: Here's the result on the platform A.\n";
    }
};

class ConcreteImplementationB : public Implementation
{
public:
    std::string operationImplementation() const override
    {
        return "ConcreteImplementationB: Here's the result on the platform B.\n";
    }
};

class Abstraction
{
protected:
    Implementation *implementation_ptr;
public:
    Abstraction( Implementation *implementation)
        : implementation_ptr(implementation)
    {

    }
    ~Abstraction()
    {

    }

    virtual std::string operation() const
    {
        return "Abstraction: Base operation with:\n"
                + implementation_ptr->operationImplementation();
    }
};

class ExtendedAbstraction : public Abstraction
{
public:
    ExtendedAbstraction( Implementation *implementation)
        : Abstraction( implementation )
    {

    }

    std::string operation() const override
    {
        return "ExtendedAbstraction: Extended operation with:\n"
                + implementation_ptr->operationImplementation();
    }
};

void clientCode( const Abstraction &abstraction)
{
    std::cout << abstraction.operation();
}

int main()
{
    Implementation *implementation_ptr = new ConcreteImplementationA();
    Abstraction *abstraction_ptr = new Abstraction( implementation_ptr );
    clientCode( abstraction_ptr );
    std::cout << std::endl;
    delete implementation_ptr;
    delete abstraction_ptr;

    implementation_ptr = new ConcreteImplementationB();
    abstraction_ptr = new ExtendedAbstraction( implementation_ptr );
    clientCode( abstraction_ptr);

    delete implementation_ptr;
    delete  abstraction_ptr;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Abstraction: Base operation with:
 * ConcreteImplementationA: Here's the result on the platform A.
 *
 * ExtendedAbstraction: Extended operation with:
 * ConcreteImplementationB: Here's the result on the platform B.
 * /

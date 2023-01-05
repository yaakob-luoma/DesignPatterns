
#include <string>
#include <iostream>

class AbstractProductA
{
public:
    virtual ~AbstractProductA(){};
    virtual std::string usefulFunctionA() const = 0;
};


class ConcreteProductA1 : public AbstractProductA
{
public:
    std::string usefulFunctionA() const override
    {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA
{
public:
    std::string usefulFunctionA() const override
    {
        return "The result of the product A2";
    }
};

class AbstractProductB
{
public:
    virtual ~AbstractProductB(){};
    virtual std::string usefulFunctionB() const = 0;
    virtual std::string anotherUsefulFunctionB( const AbstractProductA &collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
public:
    std::string usefulFunctionB() const override
    {
        return "The result of the product B1.";
    }

    std::string anotherUsefulFunctionB( const AbstractProductA &collaborator) const override
    {
        const std::string result = collaborator.usefulFunctionA();
        return "The result of the B1 collaborating with( " + result + " )";
    }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    std::string usefulFunctionB() const override
    {
        return "The result of the product B2.";
    }

    std::string anotherUsefulFunctionB( const AbstractProductA &collaborator ) const override
    {
        const std::string result = collaborator.usefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductA *createProductA() const = 0;
    virtual AbstractProductB *createProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() const override
    {
        return new ConcreteProductA1();
    }

    AbstractProductB *createProductB() const overrided
    {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() const override
    {
        return new ConcreteProductA2();
    }

    AbstractProductB *createProductB() const override
    {
        return new ConcreteProductB2();
    }
};

void clientCode( const AbstractFactory &factory )
{
    const AbstractProductA *productA_ptr = factory.createProductA();
    const AbstractProductB *productB_ptr = factory.createProductB();
    std::cout << productB_ptr->usefulFunctionB() << "\n";
    std::cout << productB_ptr->anotherUsefulFunctionB(productA_ptr) << "\n";
    delete productA_ptr;
    delete productB_ptr;
}

int main()
{
    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1 *f1_ptr = new ConcreteFactory1();
    clientCode(*f1_ptr);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2 *f2_ptr = new ConcreteFactory2();
    clientCode(*f2_ptr);
    delete f2;
    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Client: Testing client code with the first factory type:
 * The result of the product B1.
 * The result of the B1 collaborating with the (The result of the product A1.)
 *
 * Client: Testing the same client code with the second factory type:
 * The result of the product B2.
 * The result of the B2 collaborating with the (The result of the product A2.)


#include <string>
#include <iostream>

class Product
{
public:
    virtual ~Product(){}
    virtual std::string operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creator
{
public:
    virtual ~Creator(){}
    virtual Product* factoryMethod() const = 0;

    std::string someOperation() const
    {
        Product *product_ptr = factoryMethod();
        std::string result = "Creator: The same creator's code has just worked with "
                + product_ptr->operation();
        delete product_ptr;
        return  result;
    }
};

class ConcreatorCreator1 : public Creator
{
public:
    Product* factoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreatorCreator2 : public Creator
{
public:
    Product* factoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

void clientCode( const Creator &creator )
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.someOperation() << std::endl;
}

int main()
{
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator *creator_ptr = new ConcreatorCreator1();
    clientCode( *creator_ptr );
    std::cout << std::endl;
    std::cout << "App: Launched with the Concretecreator2.\n";
    Creator *creator2_ptr = new ConcreatorCreator2();
    clientCode(*creator2_ptr);

    delete creator_ptr;
    delete creator2_ptr;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * App: Launched with the ConcreteCreator1.
 * Client: I'm not aware of the creator's class, but it still works.
 * Creator: The same creator's code has just worked with {Result of the ConcreteProduct1}
 *
 * App: Launched with the ConcreteCreator2.
 * Client: I'm not aware of the creator's class, but it still works.
 * Creator: The same creator's code has just worked with {Result of the ConcreteProduct2}
 */

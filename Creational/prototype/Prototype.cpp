
#include <string>

enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype
{
protected:
    std::string name;
    float field;

public:
    Prototype(){}
    Prototype( std::string name )
    {
        this->name = name;
    }
    virtual ~Prototype(){}
    virtual Prototype* clone() const = 0;
    virtual void method( float field )
    {
        this->field = field;
        std::cout << "Call Method from "
                  << name
                  << " with field : "
                  << this->field
                  << std::endl;
    }
};

class ConcretePrototype1 : public Prototype
{
private:
    float field1;
public:
    ConcretePrototype1( std::string name, float field )
        : Prototype( name ), field1( field )
    {

    }
    Prototype* clone() const override
    {
        return new ConcretePrototype1( *this );
    }
};

class ConcretePrototype2 : public Prototype
{
private:
    flaot field2;
public:
    ConcretePrototype2( std::string name, float field )
        : Prototype( name ), field2( field )
    {

    }
    Prototype* clone() const override
    {
        return new ConcretePrototype2(*this);
    }
};

class PrototypeFactory
{
private:
    std::unordered_map<Type, Prototype *, std::hash<int>> prototypes;

public:
    PrototypeFactory()
    {
        prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1( "Prototype1 ", 50.f);
        prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2( "Prototype2 ", 60.f);
    }
    ~PrototypeFactory()
    {
        delete prototypes[Type::PROTOTYPE_1];
        delete prototypes[Type::PROTOTYPE_2];
    }
    Prototype* createPrototype( Type type )
    {
        return prototypes[type].clone();
    }
};

void client( PrototypeFactory &prototypeFactory)
{
    std::cout << "Let's create a Prototype 1\n";
    Prototype *prototype_ptr = prototypeFactory.createPrototype(Type::PROTOTYPE_1);
    prototype_ptr->method(90);
    delete prototype_ptr;

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2\n";

    prototype_ptr = prototypeFactory.createPrototype(Type::PROTOTYPE_2);
    prototype_ptr->method(10);
    delete prototype_ptr;
}

int main()
{
    PrototypeFactory *prototypeFactory_ptr = new PrototypeFactory();
    client(*prototypeFactory_ptr);
    delete prototypeFactory_ptr;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Let's create a Prototype 1
 * Call Method from Prototype1 with field : 90
 *
 * Let's create a Prototype 2
 * Call Method from Prototype2 with field : 10
 */

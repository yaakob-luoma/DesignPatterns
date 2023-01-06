
#include <string>
#include <algorithm>
#include <iostream>

class Target
{
public:
    virtual ~Target() = default;

    virtual std::string request() const
    {
        return "Target: The default target's behavior.";
    }
};

class Adaptee
{
public:
    std::string specificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Target
{
private:
    Adaptee *adaptee_ptr;
public:
    Adapter( Adaptee *adaptee ) : adaptee_ptr( adaptee ) {}
    std::string request() const override
    {
        std::string toReverse = this->adaptee_ptr->specificRequest();
        std::reverse( toReverse.begin(), toReverse.end() );
        return "Adapter: (TRANSLATED) " + toReverse;
    }
};

void clientCode( const Target *target)
{
    std::cout << target->request();
}

int main()
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target_ptr = new Target;
    clientCode(target_ptr);
    std::cout << "\n\n";
    Adaptee *adaptee_ptr = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee_ptr->specificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter *adapter_ptr = new Adapter( adaptee_ptr );
    clientCode(adapter_ptr);
    std::cout << "\n";

    delete target_ptr;
    delete adaptee_ptr;
    delete adapter_ptr;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Client: I can work just fine with the Target objects:
 * Target: The default target's behavior.
 *
 * Client: The Adaptee class has a weird interface. See, I don't understand it:
 * Adaptee: .eetpadA eht fo roivaheb laicepS
 *
 * Client: But I can work with it via the Adapter:
 * Adapter: (TRANSLATED) Special behavior of the Adaptee.
 */

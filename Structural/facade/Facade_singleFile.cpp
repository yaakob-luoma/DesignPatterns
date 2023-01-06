
#include <string>
#include <iostream>

class Subsystem1
{
public:
    std::string operation1() const
    {
        return "Subsystem1: Ready!\n";
    }
    std::string operationN() const
    {
        return "Subsystem1: Go!\n";
    }
};

class Subsystem2
{
public:
    std::string operation1() const
    {
        return "Subsystem2: Get ready!\n";
    }
    std::string operationZ() const
    {
        return "Subsystem2: Fire!\n";
    }
};

class Facade
{
protected:
    Subsystem1 *system1_ptr;
    Subsystem2 *system2_ptr;

public:
    Facade( Subsystem1 *subsystem1 = nullptr
            , Subsystem2 *subsystem2 = nullptr )
    {
        this->system1_ptr = subsystem1 ? : Subsystem1;
        this->system2_ptr = subsystem2 ? : Subsystem2;
    }
    ~Facade()
    {
        delete system1_ptr;
        delete system2_ptr;
    }
    std::string operation()
    {
        std::string result = "Facade initializes subsystems:\n";
        result += this->system1_ptr->operation1();
        result += this->system2_ptr->operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += this->system1_ptr->operationN();
        result += this->system2_ptr->operationZ();
        return result;
    }
};

void clientCode( Facade *facade )
{
    std::cout << facade->operation();
}

int main()
{
    Subsystem1 *subsystem1 = new Subsystem1();
    Subsystem2 *subsystem2 = new Subsystem2();
    Facade *facade = new Facade( subsystem1, subsystem2 );
    clientCode( facade );

    delete facade;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Facade initializes subsystems:
 * Subsystem1: Ready!
 * Subsystem2: Get ready!
 * Facade orders subsystems to perform the action:
 * Subsystem1: Go!
 * Subsystem2: Fire!
 */

#include "templatemethod.h"

class ConcreteClass1 : public AbstractClass
{
protected:
    void requiredOperation1() const override
    {
        std::cout << "ConcreteClass1 says: Implemented operation1.\n";
    }
    void requiredOperation1() const override
    {
        std::cout << "ConcreteClass1 says: Implemented operation2.\n";
    }
};
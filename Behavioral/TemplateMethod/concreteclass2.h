#include "templatemethod.h"

class ConcreteClass2 : public AbstractClass
{
protected:
    void requiredOperation1() const override
    {
        std::cout << "ConcreteClass2 says: Implemented operation1.\n";
    }
    void requiredOperation1() const override
    {
        std::cout << "ConcreteClass2 says: Implemented operation2.\n";
    }
    void hook1() const override
    {
        std::cout << "ConcreteClass2 says: Overridden hook1.\n";
    }
};

#include "abstractproductb.h"

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
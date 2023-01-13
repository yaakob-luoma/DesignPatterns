
#include "abstractproducta.h"
#include "abstractproductb.h"

class AbstractFactory
{
public:
    virtual AbstractProductA *createProductA() const = 0;
    virtual AbstractProductB *createProductB() const = 0;
};

#include <string>
#include <iostream>

class Product
{
public:
    virtual ~Product(){}
    virtual std::string operation() const = 0;
};
